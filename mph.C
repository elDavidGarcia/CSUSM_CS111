// This prograsm converts mph to m/s.
#include <iostream>
using namespace std;

int main()
{
  const double MILE = 1609;
  const double HOUR = 3600;
  double  mph;
  double ms;
  cout << "What is the miles per hour? " << endl;
  cin >> mph;

  // Convert miles per hour to meters per second.
  ms = (double)mph * MILE * (1/ HOUR);
  cout << ms << " meters per second "<< endl;
  return 0;
}  
  
