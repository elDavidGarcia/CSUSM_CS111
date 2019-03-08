/**************************************************************************/
/*PURPOSE: The program gives the average number of sick days per employee.*/
/*IMPLEMENTED BY: David Garcia                                            */
/*DATE: 10/24/15                                                          */
/*USER INFORMATION: The user inputs two sets of numbers in the in file.   */
/*IMPLEMENTATION METHOD: The program will calculate the average number of */
/* sick days per employee.                                                */
/*OVERVIEW OF SUBPARTS: The program of the main function and subparts.    */
/**************************************************************************/
#include <iostream>
using namespace std;

//Prototypes
int numEmp();
int daysEmp(int num);
double avgEmp(int num, int days);

//Start the main function.
int main()
{
  int num, days;
  double avg;

  //Call the other functions to work!
  num = numEmp();
  days = daysEmp(num);
  avg = avgEmp(num, days);
  cout << "The average number of absent days for all " << num << " employees is " << avg << "! " << endl;
  //That return zero tho.
  return 0;
}

//Get the number of employees.
int numEmp()
{
  int n;
  cout << "Enter the number of employees: ";
  cin >> n;
  //Better not accept those negatives!
  while (n < 1)
    {
      cout << "You have entered a negative value, please re-enter proper value: ";
      cin >> n;
    }
  return n;
}

//Get the number of sick days per employee.
int daysEmp(int num)
{
  int d, total = 0, count = 1;
  //Make a loop from the number of employees.
  while (num != 0)
    {
      cout << "Enter the absent days of employee number " << count << ": ";
      cin >> d;
      //Dont accept negative numbers!
      while (d < 0)
	{
	  cout << "You have entered a negative number, please re-enter a correct number: ";
	  cin >> d;
	}
      total = d + total;
      num--;
      count++;
    }
  return total;
}

//Make a fuction for the average, last one!
double avgEmp(int num, int days)
{
  double avg;
  //Calculate the average.
  avg = (double)days/num;
  return avg;
}

//You have finished great job! Now compile and run! 
