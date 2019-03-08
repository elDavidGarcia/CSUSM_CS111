// Header goes here
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int x, count = 0;
  ifstream inFile;
  ofstream outFile;

  inFile.open("Random.txt");
  outFile.open("hw7a.dat");

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
	  inFile >> x;
	}
      outFile << "There are " << count << " numbers in the file!" << endl;
      cout << "The program ran successfully! " << endl;
      cout << "View the result  at: emacs hw7a.dat " << endl;
    }
  return 0;
}
