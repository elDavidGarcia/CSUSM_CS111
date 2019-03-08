// Header goes here
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int x, count = 0, sum = 0;
  ifstream inFile;
  ofstream outFile;

  inFile.open("Random.txt");
  outFile.open("output.txt");

  if(!inFile)
    {
      cout << "Filefailure! ";
    }
  else
    {
      inFile >> x;
      while (inFile)
        {
          count++;
	  sum = x + sum;
          inFile >> x;
        }
      outFile << "There are " << count << " numbers in the file!" << endl;
      outFile << "The sum of all " << count << "numbers is " << sum << "." << endl;
      outFile << "The average of all " << count << "numbers is " << (double)sum/count << "!" << endl;
      cout << "The program ran successfully! " << endl;
      cout << "View the result  at: emacs output.txt " << endl;
    }
  return 0;
}
