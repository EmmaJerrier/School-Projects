/* 
Emma Jerrier & Matt Burton
CSC4210 - February 5th 2024

1. As superuser make the module with make command
2. (as admin) insmod jiffies.ko to install the module
3. tail /var/log/kern.log 
4. (as admin) rmmod jiffies.ko
5. tail /var/log/kern.log
*/




#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

ssize_t proc_read(struct file *file, char __user *usr_buf,
                  size_t count, loff_t *pos);

static struct proc_ops proc_ops = {
   .proc_read = proc_read,
};

int proc_init(void)
{
   printk(KERN_INFO "Loading Module (creating /proc/jiffies)\n");
   /* creates the /proc/jiffies entry */
   proc_create(PROC_NAME, 0666, NULL, &proc_ops);
   return 0;
}

void proc_exit(void)
{
   printk(KERN_INFO "Removing Module (removing /proc/jiffies)\n");
   /* removes the /proc/jiffies entry */
   printk(KERN_INFO "Removing proc Module\n");
   remove_proc_entry(PROC_NAME, NULL);
}

/* This function is called each time /proc/hello is read */

ssize_t proc_read(struct file *file, char __user *usr_buf,
                  size_t count, loff_t *pos) {

   int rv = 0;
   char buffer[BUFFER_SIZE];
   static int completed = 0;
   if (completed) {
      completed = 0;
      return 0;
   }
   completed = 1;
   rv = sprintf(buffer, "Current value of jiffies: %lu\n", jiffies);

   /* copies kernel space buffer to user space usr_buf */
   if(copy_to_user(usr_buf, buffer, rv))
      printk(KERN_INFO "Opps, copy_to_user has failed\n");
   return rv;
}

module_init(proc_init);
module_exit(proc_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Jiffies Module");
MODULE_AUTHOR("EKJ");
