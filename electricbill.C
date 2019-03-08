//electricbill.C
//CS111
//Implemented by DAG
//Simple program to calculate the amount of a 
//what to charge for the electric bill based on how
//much electricity was used 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int month, cmonth, pmonth, totalw, kover;
  double total$1, total$2, total$3;
  const double RATE1 = 8.50;
  const double RATE2 = .07525;
  const double RATE3 = .06575;
  
  //Get user input
  cout << "Enter the month using numbers 1-12 " << endl;
  cin >> month;
  if ((month < 1) || (month > 12))//Input is not in scope
    cout << "Month is invalid " << endl;
  else // Inputs are good 
    {

      cout << "Enter the current meter reading: " << endl;
      cin >> cmonth;
      
      cout << "Enter the previous meter reading: " << endl;
      cin >> pmonth;
      
      if ((cmonth < 0) || (pmonth < 0) || (cmonth < pmonth))
	cout << "Curent or previuos readings are invalid " << endl;
      else // Inputs are good
	{
	  // Calculate the total
	  totalw = cmonth - pmonth;
	  total$1 = RATE1;
	  kover = totalw  - 400;
	  total$2 = RATE1 + (RATE2 * kover);
	  total$3 = RATE1 + (RATE3 * kover);
	  
	  // Display the total
	  if (totalw <= 400)
	    cout << "You consumed " << totalw << " your amount due is " << setprecision(2) << fixed << total$1 << endl;
	  else if ((totalw > 400) && ((month >= 5) && (month <= 9)))
	    cout << "You consumed " << totalw << " your amount due is " << setprecision(2) << fixed << total$2 << endl;
	  else 
	    cout << "You consumed " << totalw << " your amount due is " << setprecision(2) << fixed << "$" << total$3 << endl;
	}
    }
  return 0;
}
 
