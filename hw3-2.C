// This program holds the prices of items, subtotal of sales, amount of sales tax, and the total.
#include <iostream>
using namespace std;

int main()
{
  double subtotal;
  double salestax;
  double total;
  double item1;
  double item2;
  double item3;
  double item4;
  double item5;
  const double TAXRATE = .07;
    
  cout << "What is the cost of item 1, 2, 3, 4, and 5?(add a space between prices) " << endl;
  cin >> item1 >> item2 >> item3 >> item4 >> item5;

    // Calculate the subtotal of the sale.
    subtotal = item1 + item2 + item3 + item4 + item5;

    // Display the subtotal.
    cout << "The subtotal is: " << subtotal << "." << endl;

    // Calculate sales tax.
    salestax = subtotal * TAXRATE;

    // Display sales tax.
    cout << "The sales tax is: " << salestax << "." << endl;

    // Calculate total.
    total = salestax + subtotal;

    // Display total.
    cout << "The total is: " << total << "." << endl;
    
    return 0;
}
