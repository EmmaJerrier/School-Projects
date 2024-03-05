/* Name: Matt Burton and Emma Jerrier
 * Date: 2/21/24
 * Class: CSC4210
 * About: This program takes in two parameters: the source file and the destination file
 * How to compile:
 *
 *    gcc file-copy.c -o file-copy
 *
 * How to run:
 *
 *    ./file-copy <source_file> <destination_file>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Precondition:
 *    - The function is called with the two pipe arrays.
 * Postcondition:
 *    - The program exits if either pipe fails to be created.
 *    - The two arrays are turned into pipes.
 */
void InitializePipes(int pipe_parent_to_child[2], int pipe_child_to_parent[2]);

/* Precondition:
 *    - The function is called with argc and argv from main.
 * Postcondition:
 *    - The program exits if the number of arguments is incorrect.
 *    - The program exits if the soure file does not exist.
 *    - The program exists if we do not have read permissions for the source file.
 *    - The source and destination file names are extracted.
 */
void HandleInput(int argc, char *argv[], char **source_file, char **destination_file);

/* Precondition:
 *    - The function is called with the source and destination file names.
 * Postcondition:
 *    - The source file is copied to the destination file.
 *    - The program exits if any error occurs during file operations.
 */
void CopyFile(char *source_file, char *destination_file, int pipe_read_fd, int pipe_write_fd);

int main(int argc, char *argv[])
{
    // Initialize the names for the files
    char *source_file;
    char *destination_file;

    // Parse command-line arguments
    HandleInput(argc, argv, &source_file, &destination_file);

    int pipe_parent_to_child[2];
    int pipe_child_to_parent[2];

    // Initialize pipes
    InitializePipes(pipe_parent_to_child, pipe_child_to_parent);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    if (pid == 0)
    {
        // Child process

        // Close write end of pipe from parent to child
        close(pipe_parent_to_child[1]);
        // Close read end of pipe from child to parent
        close(pipe_child_to_parent[0]);

        // Copy file from pipe to destination file
        CopyFile(source_file, destination_file, pipe_parent_to_child[0], pipe_child_to_parent[1]);

        // Close remaining ends of pipes
        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);
    }
    else
    {
        // Parent process

        // Close read end of pipe from parent to child
        close(pipe_parent_to_child[0]);
        // Close write end of pipe from child to parent
        close(pipe_child_to_parent[1]);

        // Open source file for reading
        int source_fd = open(source_file, O_RDONLY);
        if (source_fd == -1)
        {
            fprintf(stderr, "Error: Unable to open source file\n");
            exit(2);
        }

        // Read source file and write its contents to the pipe
        char buffer[BUFSIZ];
        ssize_t bytes_read;
        while ((bytes_read = read(source_fd, buffer, BUFSIZ)) > 0)
        {
            if (write(pipe_parent_to_child[1], buffer, bytes_read) != bytes_read)
            {
                fprintf(stderr, "Error: Failed to write to pipe\n");
                exit(3);
            }
        }

        // Close source file and pipe
        close(source_fd);
        close(pipe_parent_to_child[1]);

        // Wait for child process to finish
        wait(NULL);

        // Close remaining ends of pipes
        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);
    }

    return 0;
}

void InitializePipes(int pipe_parent_to_child[2], int pipe_child_to_parent[2])
{
    // Create pipe from parent to child
    if (pipe(pipe_parent_to_child) == -1)
    {
        fprintf(stderr, "Error: Failed to create pipe from parent to child\n");
        exit(4);
    }

    // Create pipe from child to parent
    if (pipe(pipe_child_to_parent) == -1)
    {
        fprintf(stderr, "Error: Failed to create pipe from child to parent\n");
        exit(5);
    }
}

void HandleInput(int argc, char *argv[], char **source_file, char **destination_file)
{
    // Check if the program was executed with the correct number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(6);
    }

    // Store the names for the two files
    *source_file = argv[1];
    *destination_file = argv[2];

    // Check if source file exists
    if (access(*source_file, F_OK) == -1)
    {
        fprintf(stderr, "Error: Source file does not exist\n");
        exit(7);
    }

    // Open source file to check permissions
    int source_fd = open(*source_file, O_RDONLY);
    if (source_fd == -1)
    {
        fprintf(stderr, "Error: Unable to open source file\n");
        exit(8);
    }
}

void CopyFile(char *source_file, char *destination_file, int pipe_read_fd, int pipe_write_fd)
{
    // Open source file for reading and get its permissions
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1)
    {
        fprintf(stderr, "Error: Unable to open source file\n");
        exit(9);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1)
    {
        fprintf(stderr, "Error: Unable to get source file permissions\n");
        exit(10);
    }

    // Open destination file for writing
    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
    if (destination_fd == -1)
    {
        fprintf(stderr, "Error: Unable to open destination file\n");
        exit(11);
    }

    // Define buffer for reading from the pipe
    char buffer[BUFSIZ];

    // Read from pipe and write to destination file
    ssize_t bytes_read;
    while ((bytes_read = read(pipe_read_fd, buffer, BUFSIZ)) > 0)
    {
        if (write(destination_fd, buffer, bytes_read) != bytes_read)
        {
            fprintf(stderr, "Error: Failed to write to destination file\n");
            exit(12);
        }
    }

    // Close destination file and pipe
    close(destination_fd);
    close(pipe_read_fd);
    close(pipe_write_fd);
}
