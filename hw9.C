/******************************************************************************/
/*PURPOSE: The program gives the highest, lowest, average, and sum of numbers.*/
/*IMPLEMENTED BY: David Garcia                                                */
/*DATE: 11/10/15                                                              */
/*USER INFORMATION: The user puts numbers in a file and runs the program.     */
/*IMPLEMENTATION METHOD: The program reads numbers in a file and displays the */
/*                       highest, lowest, sum, and the average.               */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and subparts.*/
/******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 100; //Declare a global constant.

//Prototypes
int readNumbers(int num[]);
int getLowest(int num[], int);
int getHigh(int num[], int);
int getSum(int num[], int);
double getAvg(int, int);

int main()
{
  //Variables
  int numbers, lowest, highest, sum;
  int num[SIZE];
  double avg;

  //Call the functions and assign a variable.
  numbers = readNumbers(num);
  lowest = getLowest(num, numbers);
  highest = getHigh(num, numbers);
  sum = getSum(num, numbers);
  avg = getAvg(numbers, sum);
  //Display the lowest, highest, sum, and average.
  cout << "The lowest number is " << lowest << endl;
  cout << "The highest number is " << highest << endl;
  cout << "The sum is " << sum << endl;
  cout << "The average is " << fixed << setprecision(2) << avg << endl;
  return 0;
}

int readNumbers(int num[])
{
  //Declare file and variables.
  ifstream inFile; 
  int n, i = 0;

  inFile.open("numbers.txt"); //Open file.

  //Make a loop to read numbers.
  inFile >> n;
  while(inFile && i < SIZE)
    {
      num[i] = n;
      i++;
      inFile >> n;
    }
  inFile.close(); //Close file
  return i; //Return the number of numbers
}
 
int getLowest(int num[], int numbers)
{
  //Variables
  int count, lowest;
  //Find the lowest number using a loop.
  lowest = num[0];
  for (count = 1; count < numbers; count++)
    {
      if(num[count] < lowest)
	lowest = num[count];
    }
  return lowest;
}

int getHigh(int num[], int numbers)
{
  //Variables
  int count, highest;
  //Find highest number using loop.
  highest = num[0];
  for(count = 1; count < numbers; count++)
    {
      if(num[count] > highest)
	highest = num[count];
    }
  return highest; 
}
	
int getSum(int num[], int numbers)
{
  int count = 0, sum = 0;
  
  //Sum the numbers in the array with a loop.
  for(count; count < numbers; count++)
    sum += num[count];
  return sum;
}

double getAvg( int numbers, int sum)
{
  double avg;

  //Find the Average but retuen as a double.
  avg = (double)sum/numbers;
  return avg;
}
  
//Finished!!!
