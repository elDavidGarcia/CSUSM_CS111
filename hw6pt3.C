/*************************************************************************************************/
/*PURPOSE: The program makes a sales report for five stores.                                     */
/*IMPLEMENTED BY: David Garcia                                                                   */
/*DATE: 10/11/15                                                                                 */
/*USER INFORMATION: The user inputs the sales of five stores.                                    */
/*IMPLEMENTATION METHOD: The program will disply the sales for the day using astriks.            */
/*OVERVIEW OF SUBPARTS: The program consist of only the main function.                           */
/*************************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  //Declare your variables.
  int store;
  int total;
  int count;

  cout << "SALES BAR CHART" << endl;
  cout << "(Each * = $100)" << endl;
  //Start first loop.
  for (store = 1;  store <= 5; store++)
    {
      cout << "Enter todays sale for store " << store << ": ";
      cin >> total;
      cout << "Store " << store << ": ";
      
      // Start second loop
      for (count = 1; count <= total/100; count++)
	{
	  cout << "*"; 
	}
  cout << endl;
    }
  return 0;
}
