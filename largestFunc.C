//Header goes here
#include <iostream>
using namespace std;

void showProgInfo();
void findLargest(int n1, int n2, int n3);

int main()
{
  int n1, n2, n3;
  showProgInfo();
  cout << "Enter three numbers using a space in between. " << endl;
  cin >> n1 >> n2 >> n3;
  cout << "The largest number is: ";
  findLargest(n1, n2, n3);
  return 0;
}

void showProgInfo()
{
  cout << "This program will ask you for three numbers and will tell you which is the largest." << endl;
}

void findLargest(int n1, int n2, int n3)
{
  if ((n1 > n2) && (n1 > n3))
    cout << n1 << endl;
  else if ((n2 > n1) && ( n2 > n3))
    cout << n2 << endl;
  else 
    cout << n3 << endl;
}

