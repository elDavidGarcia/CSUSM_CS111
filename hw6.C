/*****************************************************************************************/
/*PURPOSE: The program calculates the sum of two numbers.                                */
/*IMPLEMENTED BY: David Garcia                                                           */
/*DATE: 10/11/15                                                                         */
/*USER INFORMATION: The user inputs two numbers they would like added.                   */
/*IMPLEMENTATION METHOD: The program will calculate the sum of the two numbers.          */
/*OVERVIEW OF SUBPARTS: The program consist of only the main function.                   */
/*****************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  //Declare the integers.
  int num1, num2, total, answer;

  //Compose the do while loop.
  do 
    {
      //Gather info from user.
      cout << "Enter two numbers using a space: ";
      cin >> num1 >> num2;
      
      //Make the calculation.
      total = num1+num2;
      
      //Display the sum.
      cout << "The sum of the two numbers is: " << total << endl;
      
      //Ask if they need another calculation.
      cout << "If you would like to do another calculation enter 1 otherwise enter 0 " << endl;
      cin >> answer;
    } while (answer != 0);
  
  return 0;
}
