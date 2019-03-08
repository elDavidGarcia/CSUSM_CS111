// This program simulates a reciept at a store. 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  string moviename;
  int adulttickets;
  int childtickets;
  double adults;
  double child;
  double price;
  double grosstotal;
  double boxtotal;
  double paid;
  const double PERCENTKEPT = .20;

  // Gather information from user.
  cout << "Enter movie name: " << endl;
  getline (cin, moviename);

  cout << "Enter adult tickets sold: " << endl;
  cin >> adulttickets;

  cout << "Enter child tickets sold: " << endl;
  cin >> childtickets;

  // Calculate total money made on tickets.
  adults = adulttickets * 10.00;
  child = childtickets * 6.00;

  // Calculate gross box, net box, and distributor total.
  grosstotal = adults + child;
  boxtotal = grosstotal * PERCENTKEPT;
  paid = grosstotal - boxtotal;
  
  // Display the movie, tickets and profits.
  cout << left << setw(30) << "Movie Name: " << right << setw(13) << moviename << endl;
  cout << left << setw(30) << "Adult Tickets Sold:" << right << setw(13) << setprecision(2) << fixed << adulttickets << endl;
  cout << left << setw(30) << "Child Tickets Sold:" << right << setw(13) << setprecision(2) << fixed << childtickets << endl;
  cout << left << setw(30) << "Gross Box Office Profit:" << "$" << right << setw(12) << setprecision(2) << fixed << grosstotal << endl;
  cout << left << setw(30) << "Net Box Office Profit:" << "$" << right << setw(12) << setprecision(2) << fixed << boxtotal << endl;
  cout << left << setw(30) << "Amount Paid to Distributor:" << "$" << right << setw(12) << setprecision(2) << fixed << paid << endl;
  
  return 0; 
}
