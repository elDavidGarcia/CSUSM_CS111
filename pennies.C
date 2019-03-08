// The program 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int days;
  int num;
  double pay = 0.01;
  double total = 0.00;

  //gather info from user!
  do 
    { 
      cout << "Enter the number of days you worked: ";
      cin >> days;
      if (days <= 0)
	{
	  cout << "You have entered an invalid number! " << endl;
	}
    }while (days <= 0);
     
  //Display the total for every day.
      for (num = 1; num <= days; num++)
	{
	cout << setw(5) << num  << setw(10) << pay << endl;
	total += pay;
	pay = pay * 2;
	}

      //Calculate and display that motherfucker!
 
      cout << " " << endl;
      cout << setw(5) << "Total" << setw(10) << total << endl;
      cout << " " << endl;
      return 0;
}      
