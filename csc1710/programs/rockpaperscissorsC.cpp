/*
Emma Jerrier
~/csc1710/programs/rockpaperscissorsC
sources=Textbook
We had to write a program to give the user a choice between rock paper scissors and rock paper scissors lizard spock and use functions to have the computer randomly generate one as well and keep track of the score for best out of 5  
!!!96 point program!!!
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void gameTest(int gameInput, string userChoice, int &man, int &computer);
void LizardSpock(int gameInput, string userChoice, int &man, int &computer);
void printScore(int man, int computer);
string winner(int man, int computer);
void firstGame(int &man, int &computer, int gameInput, string userChoice);
void secondGame(int &man, int &computer, int gameInput, string userChoice); 

int main ()
{

   int man=0, computer=0, gameChoice, gameInput;
   string userChoice;
// Used this to make the rand function actually randomize
   srand(time(0));
// Asked for either R/P/S or R/P/S/L/SP
   cout<<"Please input a 1 if you would like to play Classic Rock, Paper, Scissors. Or input a 2 if you would like to play Rock, Paper, Scissors, Lizard, Spock: "<<endl;
   cin>>gameChoice;
// a while loop in case they give a number that isn't 1 or 2
   while(gameChoice>2 || gameChoice<=0)
   {
   cout<<"You've input an option not available! Please try again:"<<endl;
   cin>>gameChoice;
   }
// I have been having issues with my while loop so I'm trying to figure it out ---- I had done || instead of && 

   while(man<3 && computer<3)
      {
// only rock paper scissors
      if(gameChoice==1)
      {
         firstGame(man, computer, gameInput, userChoice);
      }
// only rock paper scissors lizard spock      
      if(gameChoice==2)
      {
         secondGame(man, computer, gameInput, userChoice);
      }
      }
// this prints out who wins, the person or the computer
   cout<<winner(man, computer)<<endl;

   return 0;
} 

//This is for the Classic Rock Paper Scissors game, I did multiple if elses to test each possibility and did a pass by reference for the score for both the computer and the player so it would update each time without having to return anything
// 1 = Rock, 2=Paper, 3=Scissors
void gameTest(int gameInput, string userChoice, int &man, int &computer)
{
   if(gameInput==1 && userChoice=="SCISSORS")
   {
   cout<<"Rock vs. Scissors!"<<endl<<"Rock crushes Scissors, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==1 && userChoice=="PAPER")
   {
   cout<<"Rock vs. Paper!"<<endl<<"Paper covers Rock, You win!"<<endl;
   man++;
   }
   else if(gameInput==2 && userChoice=="SCISSORS")
   {
   cout<<"Paper vs. Scissors!"<<endl<<"Scissors cuts Paper, You win!"<<endl;
   man++;
   }
   else if(gameInput==2 && userChoice=="ROCK")
   {
   cout<<"Paper vs Rock!"<<endl<<"Paper covers Rock, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==3 && userChoice=="ROCK")
   {
   cout<<"Scissors vs. Rock!"<<endl<<"Rock crushes Scissors, You win!"<<endl;
   man++;
   }
   else if(gameInput==3 && userChoice=="PAPER")
   {
   cout<<"Scissors vs Paper!"<<endl<<"Scissors cut Paper, You lose..."<<endl;
   computer++;
   }
   else
   cout<<"Draw! Try again!"<<endl;
}

//This is for the Advanced Rock Paper Lizard Spock which I did the same if else statements and passed by reference the player's score and the computer
//1= Rock, 2= Paper, 3= Scissors, 4= Lizard, 5= Spock
void LizardSpock(int gameInput, string userChoice, int &man, int &computer)
{
//ROCK
   if(gameInput==1 && userChoice=="SCISSORS")
   {
   cout<<"Rock vs. Scissors!"<<endl<<"Rock crushes Scissors, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==1 && userChoice=="PAPER")
   {
   cout<<"Rock vs. Paper!"<<endl<<"Paper covers Rock, You win!"<<endl;
   man++;
   }
   else if(gameInput==1 && userChoice=="LIZARD")
   {
   cout<<"Rock vs. Lizard!"<<endl<<"Rock crushes Lizard, You lose..."<<endl;
   computer++;
   }
    else if(gameInput==1 && userChoice=="SPOCK")  
   {
   cout<<"Rock vs. Spock!"<<endl<<"Spock vaporizes Rock, You win!"<<endl;
   man++;
   }
// PAPER
   else if(gameInput==2 && userChoice=="SCISSORS")
   {
   cout<<"Paper vs. Scissors!"<<endl<<"Scissors cuts Paper, You win!"<<endl;
   man++;
   }
   else if(gameInput==2 && userChoice=="ROCK")
   {
   cout<<"Paper vs Rock!"<<endl<<"Paper covers Rock, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==2 && userChoice=="LIZARD")
   {
   cout<<"Paper vs Lizard!"<<endl<<"Lizard eats Paper, You win!"<<endl;
   man++;
   }
   else if(gameInput==2 && userChoice=="SPOCK")
   {
   cout<<"Paper vs Spock!"<<endl<<"Paper disproves Spock, You lose..."<<endl;
   computer++;
   }
//SCISSORS
   else if(gameInput==3 && userChoice=="ROCK")
   {
   cout<<"Scissors vs. Rock!"<<endl<<"Rock crushes Scissors, You win!"<<endl;
   man++;
   }
   else if(gameInput==3 && userChoice=="PAPER")
   {
   cout<<"Scissors vs Paper!"<<endl<<"Scissors cut Paper, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==3 && userChoice=="LIZARD")
   {
   cout<<"Scissors vs Lizard!"<<endl<<"Scissors decapitates Lizard, You lose..."<<endl;
   computer++;
   }
   else if(gameInput==3 && userChoice=="SPOCK")
   {
   cout<<"Scissors vs Spock!"<<endl<<"Spock crushes Scissors, You win!"<<endl;
   man++;
   }
//LIZARD
   else if(gameInput==4 && userChoice=="ROCK")
   {
   cout<<"Lizard vs. Rock!"<<endl<<"Rock crushes Lizard, You win!"<<endl;
   man++;
   }
   else if(gameInput==4 && userChoice=="PAPER")
   {
   cout<<"Lizard vs. Paper!"<<endl<<"Lizard eats Paper, you lose..."<<endl;
   computer++;
   }
   else if(gameInput==4 && userChoice=="SCISSORS")
   {
   cout<<"Lizard vs. Scissors!"<<endl<<"Scissors decapitates Lizard, you win!"<<endl;
   man++;
   }
   else if(gameInput==4 && userChoice=="SPOCK")
   {
   cout<<"Lizard vs. Spock!"<<endl<<"Lizard poisons Spock, you lose..."<<endl;
   computer++;
   }
//SPOCK
   else if(gameInput==5 && userChoice=="ROCK")
   {
   cout<<"Spock vs. Rock!"<<endl<<"Spock vaporizes Rock, you lose..."<<endl; 
   computer++;
   }
   else if(gameInput==5 && userChoice=="PAPER")
   {
   cout<<"Spock vs. Paper!"<<endl<<"Paper disproves Spock, you win!"<<endl;
   man++;
   }
   else if(gameInput==5 && userChoice=="SCISSORS")
   {
   cout<<"Spock vs. Scissors!"<<endl<<"Spock smashes Scissors, you lose..."<<endl;
   computer++;
   }
   else if(gameInput==5 && userChoice=="LIZARD")
   {
   cout<<"Spock vs. Lizard!"<<endl<<"Lizard poisons Spock, you win!"<<endl;
   man++;
   }
// DRAW
   else
   cout<<"Draw! Try again!"<<endl;
}
// this prints the score after each round and reminds that the best out of five wins, the scores are both passed by value since they're just being printed rather than updated
void printScore(int man, int computer)
{
 cout<<"The score is "<<man<<" to "<<computer<<endl;
 cout<<"Best out of 5 wins!"<<endl;
}

// this I just added outside the while loop to say who was the overall winner at the very end
string winner(int man, int computer)
{
string win;
   if(man<computer)
   {
   win = "The computer wins";
   return win;
   }
   else
   {
   win = "You beat the computer!";
   return win;
   }
}

//I had originally had this in my main funtion but moved it all to a function where I just take the user's input, make sure it's valid and run each of the functions
void secondGame(int &man, int &computer, int gameInput, string userChoice)
{
         cout<<"Please input ROCK, PAPER, SCISSORS, LIZARD, or SPOCK in all caps:"<<endl;
         cin>>userChoice;

         while(userChoice!="ROCK" && userChoice!="PAPER" && userChoice!="SCISSORS" && userChoice!="LIZARD" && userChoice!="SPOCK")
         {
         cout<<"Improper input! Please try again..."<<endl;
         cin>>userChoice;
         }

         gameInput=(rand()%5)+1;
         LizardSpock(gameInput, userChoice, man, computer);
         printScore(man, computer);
}

// This was originally in the main function but moved it to its own function to take the user's input, validate it and run the separate functions
void firstGame(int &man, int &computer, int gameInput, string userChoice)
{
         cout<<"Please input ROCK, PAPER, or SCISSORS in all caps:"<<endl;
         cin>>userChoice;
// I made the gameInput = the random number my function generated 
         
         while(userChoice!="ROCK" && userChoice!="PAPER" && userChoice!="SCISSORS")
         {
         cout<<"Improper input! Please try again..."<<endl;
         cin>>userChoice;
         }
         
         gameInput=(rand()%3)+1;
         gameTest(gameInput, userChoice, man, computer);
         
         printScore(man, computer);
}
