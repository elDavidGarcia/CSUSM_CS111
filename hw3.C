// This program holds the prices of items, subtotal of sales, amount of sales tax, and the total.
#include <iostream>
using namespace std;

int main()
{
  double subtotal;
  double salestax;
  double total;
  double item1 = 15.95;
  double item2 = 24.95;
  double item3 = 6.95;
  double item4 = 12.95;
  double item5 = 3.95;
  const double TAXRATE = .07;
    
  cout << "Item one cost " << item1 << ", item 2 cost " << item2 << ", item 3 cost " << item3 << ", item 4 cost " << item4 << ", and item 5 cost " << item5 << "." << endl;

    // Calculate the subtotal of the sale.
    subtotal = item1 + item2 + item3 + item4 + item5;

    // Display the subtotal.
    cout << "The subtotal is: " << subtotal << "." << endl;

    // Calculate sales tax.
    salestax = subtotal * TAXRATE;

    // Display sales tax.
    cout << " The sales tax is: " << salestax << "." << endl;

    // Calculate total.
    total = salestax + subtotal;

    // Display total.
    cout << " The total is: " << total << "." << endl;
    
    return 0;
}
