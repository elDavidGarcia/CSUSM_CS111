/********************************************************************************/
/*PURPOSE: Gets information, displays it on a table, and finds the highest.     */
/*IMPLEMENTED BY: DAG                                                  */
/*DATE: 11/21/15                                                                */
/*USER INFORMATION: The user puts inputs name, number, and score for 12 players.*/
/*IMPLEMENTATION METHOD: The program gets name, number, and score of a player 12*/
/*                       times then makes a table and finds the person with the */
/*                       most poonts.                                           */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and subparts.  */
/********************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 12; //Make the size for 12 players.

struct player //Make the strucure 
{
  string name;
  int number;
  int points;
};

//Prototypes for main
void getPlayerInfo(player ar[]);
void showInfo(player ar[]);
int getTotalPoints(player ar[]);
void showHigh(player ar[]);


int main()
{
  player ar[SIZE]; //Make array to hold values.
  int total;
  //Call functions
  getPlayerInfo(ar);
  showInfo(ar);
  total = getTotalPoints(ar);
  cout << endl << "Total points: " << total << endl;
  showHigh(ar);
  return 0;
}

void getPlayerInfo(player ar[])
{
  int i = 0;
  for(i; i < SIZE; i++) //Loop for input.
    {
      cout << "Enter first name of player #" << i+1 << ": ";
      cin >> ar[i].name;
      cout << "Enter number of player #" << i+1 << ": ";
      cin >> ar[i].number;
      while(ar[i].number < 0)//Input validation
	{
	  cout << "No negative numbers! Re-enter number: ";
	  cin >> ar[i].number;
	}
      cout << "Enter points for player #" << i+1 << ": ";
      cin >> ar[i].points;
      while(ar[i].points < 0)//Input validation
	{
          cout << "No negative numbers! Re-enter number: ";
          cin >> ar[i].points;
        }
      cout << endl;
    }
}

void showInfo(player ar[])
{
  int i = 0;
  cout << left << setw(10) << "Name: " << setw(8) << "Number: " << setw(8) << "Points: " << endl; //Table header
  for(i; i < SIZE; i++) //Table information
    cout << left 
	 << setw(10) << ar[i].name 
	 << setw(8) << ar[i].number
	 << setw(8) << ar[i].points << endl;
}

int getTotalPoints(player ar[])
{
  int i = 0, total;
  for(i; i < SIZE; i++) //Add up array
    total = total + ar[i].points;
  return total;
}

void showHigh(player ar[])
{
  int i = 1, count = 0;
  int high = ar[0].points;
  for(i; i < SIZE; i++) //Find highest
    {
      if(ar[i].points > high)
	{
	high = ar[i].points;
	count = i; //Count for displaying
	}
    }
  cout << ar[count].name << " (player #" << ar[count].number << ") scored the most points! " << endl; 
}
  
//Done!
