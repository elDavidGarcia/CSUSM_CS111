// This program is to get me credit in cs111 lab lol.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int month;

  // Gather the info from user.
  cout << "Enter month using numbers 1-12 " << endl;
  cin >> month;

  switch(month)
    {
    case 1 : 
    case 2 : 
    case 12: cout << "It's winter! Grab a coat. " << endl;
      break;
    case 3 :
    case 4 :
    case 5 : cout << "It's spring! Go smell the flowers. " << endl; 
      break;
    case 6 : 
    case 7 :
    case 8 : cout << "It's summer! Time to work on that tan. " << endl; 
      break;
    case 9 :
    case 10 :
    case 11 : cout << "It's fall! Look at the beautiful leaves. " << endl;
      break;
 default : cout << "You have entered an invlaid month! " << endl;
    }  
   return 0;
}
