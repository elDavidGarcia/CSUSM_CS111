/*****************************************************************************************/
/*PURPOSE: The program calculates the users phone bill.                                  */
/*IMPLEMENTED BY: David Garcia                                                           */
/*DATE: 10/03/15                                                                         */
/*USER INFORMATION: The user inputs the package they have choosen and minutes they used. */
/*IMPLEMENTATION METHOD: The program will calculate the users phone bill.                */
/*OVERVIEW OF SUBPARTS: The program consist of only the main function.                   */
/*****************************************************************************************/
#include <iostream>
using namespace std;

int main ()
{
  //Set all known info.
  int  min;
  char PKG;
  const double PKG1A = 39.99;
  const double PKG2A = 59.99;
  const double PKG3 = 69.99;
  const double PKG1B = 0.45;
  const double PKG2B = 0.40;
  const int min1 = 450;
  const int min2 = 900;
  double total;

  //Gather info from the user.
  cout << "What package have you purchased? Enter A, B, or C. " << endl;
  cin >> PKG;
  if ((PKG != 'A') && (PKG != 'B') && (PKG != 'C'))
    {
    cout << "The package you have entered is invalid. " << endl;
    }
  else 
    {
      {
  cout << "How many minutes did you use? " << endl;
  cin >> min;
      }
  //Calculations and else, if statements.

  if ((PKG) == 'A' && (min <= 450))
      
    {
	   total = 39.99;
  cout << "You have slected package A and your total this month is $" << total << endl;
    }
  else if (PKG == 'A' && min>450)
    {
	   total = 39.99 + ((min - min1) * PKG1B);
  cout << "You have selected package A and your total this month is $" << total << endl;
    }
  else if (PKG == 'B' && min <= 900)
    {
           total = 59.99;
  cout << "You have selected package B and your total this month is $" << total << endl;
    }
  else if (PKG == 'B' && min > 450) 
    {
	   total = 59.99 + ((min - min2) * PKG2B);
  cout << "You have selected package B and your total this month is $" << total << endl;
    }
  else
    {
    cout << "You have selected package C and your total this month is $" << PKG3 << endl;
    }
    }

  return 0;
}    
