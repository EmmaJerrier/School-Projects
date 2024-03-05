/*
Name: Emma Jerrier
Date: 9/16/2021
Class: Csc1710
Path: /home/students/ejerrier/csc1710/lab4
Description: We had to write an assignment to prompt the user to input multiple lab, quiz, program, and test scores then weigh them and calculate the current average.
Assisted by: Mia Glenn
*/

#include <iostream>

using namespace std;

int main ()
{
   double lab1, lab2, lab3, lab4, quiz1, quiz2, quiz3, program, test, labavg, quizavg, labW, quizW, programW, testW, cavg;
   string name;
//   cout<<"Enter your name please"<<endl;
// I added a variable for the name and put a sample name in each of the data files (Emma, Dr.Titus, and Emma)  
   cin>>name;
   cout<<"Hey there "<<name<<"!"<<endl;
   cout<<"Let's calculate your current grade!!!! Ready?"<<endl;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//   cout<<"Enter your first lab grade:"<<endl;
   cin>>lab1;
//   cout<<"Enter your second lab grade:"<<endl;
   cin>>lab2;
//   cout<<"Enter your third lab grade:"<<endl;
   cin>>lab3;
//   cout<<"Enter your fourth lab grade:"<<endl;
   cin>>lab4;
// I prompted them to enter each individual lab grade so I can now calculate the average of the four labs so I can turn that into the weighted value I need for the current average calculation //
   labavg = ((lab1+lab2+lab3+lab4)/4)*10;
   cout<<"Your lab average is "<<labavg<<"%"<<endl;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//  cout<<"Enter your first quiz grade:"<<endl;
   cin>>quiz1;
//  cout<<"Enter your second quiz grade:"<<endl;
   cin>>quiz2;
//  cout<<"Enter your third quiz grade:"<<endl;
   cin>>quiz3;
// I prompted them to enter each individual quiz grade and then calculated the average of the 3 quizzes which I will use later in the program to calculate the weighted average //  
   quizavg = ((quiz1+quiz2+quiz3)/3)*10;
// For both the Lab Average and Quiz average I multiplied each by 10 so it would be out of 100 rather than out of 10 because the program and test grade are out of 100 rather than 10//
   cout<<"Your quiz average is "<<quizavg<<"%"<<endl;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//   cout<<"Enter your program grade:"<<endl;
   cin>>program;
//   cout<<"Enter your test grade:"<<endl;
   cin>>test;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
// In the section below, I set up specific variables for the weighted average and did all those calculations before doing the final, current average calculation //
   labW = labavg*.1;
   quizW = quizavg*.1;
   programW = program*.06;
   testW = test*.1;
   cavg = ((labW+quizW+programW+testW)/36)*100;
   cout<<"Your current average is "<<cavg<<"%"<<endl;
   cout<<"Let's get studying "<<name<<"!"<<endl;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   cout<<"Fun fact of the day: The first programmer in the entire world was a woman! Her name was Ada Lovelace and she was born in 1815!"<<endl;
   cout<<"Girl Power!"<<endl;

   return 0;
}

