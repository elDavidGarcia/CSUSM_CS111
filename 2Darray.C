//2Darray.C
//CS111
//Implemented by DAG
//Simple program that uses a 2D array as a table to keep 
//track of scores.

#include <iostream>
#include <iomanip>
using namespace std;

//Sizes for the Array
const int SIZE_STU = 5;
const int SIZE_TEST = 3;

//Function Prototypes
void fillArray(int scores[][ SIZE_TEST]);
void printArray(const int scores[][ SIZE_TEST]);

int main()
{
  int scores [SIZE_STU][SIZE_TEST]; //Create 2D Array

  fillArray(scores); //Fill the 2D array
  printArray(scores); //Print 2D Array
  
  return 0;
}

//Function will make a "table" from a 2D array. It goes in order by
//test to enter the students grade in the test.
void fillArray(int scores[][SIZE_TEST])
{
  int test, stu;
  //As long as test is less than the column size it will keep filling
  for (test = 0; test < SIZE_TEST; test++)
    {
      cout << "Enter the scores for test " << test+1 << " : " << endl;
      //Asks the students score for the test #
      for (stu=0; stu < SIZE_STU; stu++)
	{
	  cout << "Student #" << stu + 1 << ": ";
	  cin >> scores[stu][test];
	}
    }
}

//Function will make a "table" from the 2D array. It prints out the 
//students number, test scores, and average.
void printArray(const int scores[][SIZE_TEST])
{
  int tnum = 0, num = 0;
  cout << endl;
  //Set up the top row with all the names of the columns
  cout << setw(8) << "Test #" << setw(12) << "Student 1" << setw(12) << "Student 2" 
       << setw(12) << "Student 3" << setw(12) << "Student 4" << setw(12) << "Student 5" 
       << setw(12) << "Average " << endl;
  //Display students scores from 2D Array
  for(int i = 0; i < SIZE_TEST;  i++)
    {
      cout << setw(8) << i+1; //Displays test number
      //Loop to retrieve students scores for test i+1
      for(int j = 0; j < SIZE_STU; j++)
	{
	  cout << setw(12) << scores[j][i];
	  tnum += scores[j][i];//Accumulates all students scores for test i+1
	}
      //Calculate the average for test i+1
      cout << setw(12) << fixed << setprecision(1) << (double)tnum/SIZE_STU << endl;
      tnum = 0;//reset the accumulator
    }
  //Make a final row for student's tests average
  cout << setw(8) << "Average";
  //Loop goes through each student
  for(int j = 0; j < SIZE_STU; j++)
    {
      //Accumulate student's scores
      for(int i = 0; i < SIZE_TEST;  i++)
	num += scores [j][i];
      //Calculate average.
      cout << setw(12) << fixed << setprecision(1) << (double)num/SIZE_TEST;
      num = 0;//Reset accumulator
    }
  cout << endl;
  cout << endl;
}

