/******************************************************************************/
/*PURPOSE: The program gives the highest, lowest, average, and sum of numbers.*/
/*IMPLEMENTED BY: David Garcia                                                */
/*DATE: 11/10/15                                                              */
/*USER INFORMATION: The user puts numbers in a file and runs the program, then*/
/*                  inputs information.                                       */
/*IMPLEMENTATION METHOD: The program reads numbers in a file and displays the */
/*                       sum and the average, then finds the lowest and       */ 
/*                       higest inside a row.                                 */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and subparts.*/
/******************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 12, COLS = 4; //Global constants

//Prototypes
int getInfo(int [][COLS], int);
int getTotal(int [][COLS], int);
double getAverage(int, int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
  int total, numbers, rtotal, ctotal, hrow, lrow;
  double avg;
  int ar[ROWS][COLS];
  //Call the first functions.
  numbers = getInfo(ar, ROWS);
  total = getTotal(ar, ROWS);
  avg = getAverage(numbers, total);
  cout << "The numbers in the file are: " << endl;
  //Display the numbers in the file. Makes life easier. (Optional)
  for(int x = 0; x < ROWS; x++)
    {
      for(int y = 0; y < COLS;  y++)
        cout << ar[x][y] << " ";
      cout << endl;
    }
  cout << endl;
  //Display sum and average.
  cout << "The sum of all " << numbers << " numbers is " << total << "! " << endl;
  cout << "The average is " << fixed << setprecision(2) << avg << "! " << endl;
  cout << endl;
  //Call second set of functions.
  rtotal = getRowTotal(ar, ROWS);
  ctotal = getColumnTotal(ar, ROWS);
  hrow = getHighestInRow(ar, ROWS);
  lrow = getLowestInRow(ar, ROWS);
  cout << endl;
  //Display the rest.
  cout << "The total for the row you have selected is " << rtotal << ". " << endl;
  cout << "The total for the column you have selected is " << ctotal << ". " << endl;
  cout << "The higest number in the row you picked is " << hrow << ". " << endl;
  cout << "The lowest number in the row you picked is " << lrow << ". " << endl;
  cout << endl;
  return 0;
}
int getInfo(int ar[][COLS], int ROWS)
{
  ifstream inFile;
  int n, count = 0;

  inFile.open("2Dnumbers.txt"); //Open file.

  //Make a loop to read numbers.
  inFile >> n;
  while(inFile)
    {
      for(int i = 0; i < ROWS; i++)
	{
	  for(int j = 0; j < COLS; j++)
	    {
	      ar[i][j] = n;
	      inFile >> n;
	      count++;
	    }
	}
    }
  inFile.close(); //Close file
  cout << endl;
 
  return count;
}

int getTotal(int ar[][COLS], int ROWS)
{
  int total = 0;
  //Make a nested loop to sum up all the numbers.
  for(int i = 0; i < ROWS; i++)
    {
      for(int j = 0; j < COLS; j++)
	total += ar[i][j];
    }
  return total;
}
double getAverage(int numbers, int total)
{
  double avg;
  //Use the total and count to find the average.
  avg = (double)total/numbers;
  return avg;
}
int getRowTotal(int ar[][COLS], int ROWS)
{
  int total = 0, ans1;
  cout << "Enter the row number(starting at 1) you would like to sum up: ";
  cin >> ans1;
  while((ans1 < 1) || (ans1 > ROWS)) //Dont go outside parameters!
    {
      cout <<"Invalid row number! Re-enter value: ";
      cin >> ans1;
    }
  ans1 = ans1 - 1;
  //Make loop for the sum.
  for(int i = 0; i < COLS; i++)
    total += ar[ans1][i];
  return total;
}

int getColumnTotal(int ar[][COLS], int ROWS)
{
  int total = 0, ans;
  cout << "Enter the column number(starting at 1) you would like to sum up: ";
  cin >> ans;
  while((ans < 1) || (ans > COLS)) //Check the parameters!
    {
      cout <<"Invalid column number! Re-enter value: ";
      cin >> ans;
    }
  ans = ans - 1;
  //What time is it? Loop time!
  for(int i = 0; i < ROWS; i++)
    total += ar[i][ans];
  return total;
}

int getHighestInRow(int ar[][COLS], int ROWS)
{
  int highest, ans;
  //Ask user for a row.
  cout << "Pick a row number(starting at 1) to find the highest number: ";
  cin >> ans;
  while((ans < 1) || (ans > ROWS)) //Just checking parameters.
    {
      cout <<"Invalid row number! Re-enter value: ";
      cin >> ans;
    }
  ans = ans - 1;
  highest = ar[ans][0];
  //Loop to find higest.
  for(int i = 1; i < COLS; i++)
    {
      if(ar[ans][i] > highest)
	highest = ar[ans][i];
    }
  return highest;
}

int getLowestInRow(int ar[][COLS], int ROWS)
{
  int lowest, ans;
  //Interact with the user. Ask for a row.
  cout << "Pick a row number(starting at 1) to find the lowest number: ";
  cin >> ans;
  while((ans < 1) || (ans > ROWS)) //Make sure they stay within the parameters.
    {
      cout <<"Invalid row number! Re-enter value: ";
      cin >> ans;
    }
  ans = ans - 1;
  lowest = ar[ans][0];
  //Make loop to find the lowest. Last loop I promise! 
  for(int i = 1; i < COLS; i++)
    {
      if(ar[ans][i] < lowest)
        lowest = ar[ans][i];
    }
  return lowest;
}

//Done give self pat on the back!

