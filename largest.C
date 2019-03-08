// This program gets the largest number out of four numbers.
#include <iostream>
using namespace std;

int main()
{
  int n1, n2, n3, n4, largest;

  //Get information from user.
  cout << "Enter four numbers using a spacebar in between: " <<endl;
  cin >> n1 >> n2 >> n3 >> n4;

  //calculate the largest number.
  if (n1 > n2)
    largest = n1;
  else 
    largest = n2;

  if (n3 > largest)
    largest = n3;

  if (n4 > largest)
    largest = n4;

  // Display the largest number.
  cout << "The largest number is: " << largest << endl;
  return 0;
}
