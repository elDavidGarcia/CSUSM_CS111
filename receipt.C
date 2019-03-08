// This program simulates a reciept at a store. 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  string date;
  string name;
  string item;
  double price;
  double salestax;
  double total;
  const double TAXRATE = .0775;

  // Gather information from user.
  cout << "Enter sales person's name: " << endl;
  getline (cin, name);

  cout << "Enter today's date: " << endl;
  cin >> date;

  cout << "Iteam name: " << endl;
  cin >> item;

  cout << "Enter the price of the item: " << endl;
  cin >> price;

  // calculate the sales tax and total.
  salestax = price * TAXRATE;
  total = price + salestax;
  
  // Display the cost of the item, sales tax, and total.
  cout << " " << endl;
  cout << "-------------------------------" << endl;
  cout << " " << endl;
  cout << "\"Your Friendly Neighbor Store\"" << endl;
  cout << " " << endl;
  cout << setw(31) <<  date << endl;
  cout << setw(31) << name << endl;
  cout << left << setw(20) << item << "$" << right << setw(10) << setprecision(2) << fixed << price << endl;
  cout << left << setw(20) << "Sales Tax" << "$" << right << setw(10) << salestax << endl;
  cout << left << setw(20) << "Total" << "$" << right << setw(10) << total << endl;
  
  cout << " " << endl;
  cout << "-------------------------------" << endl;
  cout << " " << endl;

  // Thank the customer. 
  cout << "Thank you for shopping with us!" << endl;
  
  return 0;
} 
