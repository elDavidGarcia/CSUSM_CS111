/*************************************************************************************************/
/*PURPOSE: The program calculates the pay of an employee.                                        */
/*IMPLEMENTED BY: David Garcia                                                                   */
/*DATE: 10/11/15                                                                                 */
/*USER INFORMATION: The user inputs the gross pay, state tax, federal tax, and FICA withholding. */
/*IMPLEMENTATION METHOD: The program will calculate the employee's pay after deductions.         */
/*OVERVIEW OF SUBPARTS: The program consist of only the main function.                           */
/*************************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  //Declare variables.
  int employee;
  double pay, stax,ftax, fica, total, totaltax;
  
  //Gather info from user.
  cout << "Enter employee number: ";
  cin >> employee;
  
  //Make a loop for the empoyee number.
  while (employee <= 0)
    {
      cout << "The employee number you have entered is invalid!" << endl;
      cout << "Enter a valid employee number: ";
      cin >> employee;
    }
  //Time for the BIG loop!
  while (employee != 0)
    { 
      //Make loops inside the BIG loop to correct any mistakes from user.
      while (employee < 0)
	{
	  cout << "The employee number you have entered is invalid!" << endl;
	  cout << "Enter a valid employee number: ";
	  cin >> employee;
	}

      cout << "Enter gross pay: ";
      cin >> pay;
      while (pay < 0)
	{
	  cout << "Invalid grosspay! Please enter valid grosspay: ";
	  cin >> pay;
	}
    
      cout << "Enter state tax: ";
      cin >> stax;
      while ((stax < 0) || (stax > pay))
	{
	  cout << "Invalid state tax! Please enter valid state tax: ";
	  cin >> stax;
	}
     
      cout << "Enter federal tax: ";
      cin >> ftax;
      while ((ftax > pay) || (ftax < 0))
	{
	  cout << "Invalid federal tax! Please enter valid federal tax: ";
	  cin >> ftax;
	}
       
      cout << "Enter FICA withholdings: ";
      cin >> fica;  
      while ((fica < 0) || (fica > pay))
	{
	  cout << "Invalid FICA witholding! Please enter valid FICA withholding: ";
	  cin >> fica;
        }
         
      totaltax = stax + ftax + fica;
      while ((totaltax > pay) || (stax < 0) || (ftax < 0) || (fica < 0))
	{
	  cout << "There has been an error with the info you have entered! " << endl;
	  cout << "Please re-enter the following values: " << endl;

	  cout << "Gross pay: ";
	  cin >> pay;
	  cout << "State tax: ";
	  cin >> stax;
	  cout << "Federal tax: ";
	  cin >> ftax;
	  cout << "FICA witholdings: ";
	  cin >> fica;
	 
	  //Calculate the total deductions.
	  totaltax = stax + ftax + fica;
	}
      //Calculate the total pay after deductions, sad face.
      total = pay - totaltax;
      
      //Dispaly the total for the user to make him/her sad. 
      cout << "The gross pay is $" << pay << endl;
      cout << "The state tax is $" << stax << endl;
      cout << "The federal tax is $" << ftax << endl;
      cout << "The FICA withholdings is $" << fica << endl;
      cout << "The total pay is $" << total << endl;
      
      //Ask if they would like to use your program again because its so rad!
      cout << "Enter another employee number or enter 0 if you are done. " << endl;
      cin >> employee;
     
    }
  
  //Put the return zero (This comment is useless).
  return 0;
  
  //Close the int main bracket (This is another usless comment, but red is my favorite color).
}

