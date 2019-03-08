//evenodd.C
//CS111
//Implemented by DAG
//Simple program gets user input and checks if it is 
//odd or even. Keeps a tally of how many odd and even inputs
//were given. Adds all inputs and finds average. 
#include <iostream>
using namespace std;

int main()
{
  int num;
  int counte = 0;
  int countd = 0;
  int total = 0;
  double avg;

  //Get user input
  cout << "Enter a number (enter 0 to quit): ";
  cin >> num;

  //Make the loop.
  while (num != 0)//Zero is neither odd or even
    {
      if (num%2 == 0)//Mod by two, if its 0 it's even
	{
	  counte++;//increment even count
	  cout << "Even Number" << endl;
	}
      else 
	{
	  countd++;//Increment odd count
	  cout << "Odd Number" << endl;
	}
      total = total + num;//add to total acumulator
      cout << "Enter a number (enter 0 to quit): ";
      cin >> num;
    }
 
  if ((counte <= 0)&&(countd <= 0))//No input
    cout << "You have not entered a number! " << endl;
  
  else 
    {
      //Calculate the average
      avg = (double)total/(counte + countd);
      
      //Display totals
      cout << counte << " even numbers " <<endl;
      cout << countd << " odd numbers " << endl;
      cout << "The average is " << avg << endl;
    }

  return 0;
}
