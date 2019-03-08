/********************************************************************************/
/*PURPOSE: Gets a word and reverses it.                                         */
/*IMPLEMENTED BY: DAG                                                           */
/*DATE: 12/7/15                                                                 */
/*USER INFORMATION: The user inputs a word.                                     */
/*IMPLEMENTATION METHOD: The program gets a word and reverses the order of the  */
/*                       letters                                                */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and a subpart. */
/********************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

void reverse(string);

int main()
{
  string x;
  cout << "Enter a word: ";
  cin >> x;
  reverse(x);
  cout << endl;
  return 0;
}

void reverse(string x)
{
  if(x == "")
    return;
  else 
    {
      cout << x[x.length() - 1];
      reverse(x.substr(0, x.length() - 1));
    }
}
