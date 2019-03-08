// Header goes here
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  int num;
  int total = 0;
  int count = 0;
  int t1,t2,t3;
  int total2 = 0;
  int total3 = 0;
  string fn;
  string ln;
  ifstream inFile;
  ofstream outFile;

  inFile.open("student.dat");
  outFile.open("result.dat");

  if (!inFile)
    {
      cout << "Cannot open file" << endl;
    }
  else 
    {
      inFile >> fn >> ln >> t1 >> t2 >> t3;
      while (inFile)
	{
	  total += t1;
	  total2 += t2;
	  total3 += t3;
	  count++;
	  inFile >> fn >> ln >> t1 >> t2 >> t3;
	}
      if (count != 0)
	{
	  outFile << "Average for test 1: " << fixed << setprecision(3) << float(total)/count << endl;
	  outFile << "Average for test 2: " << fixed << setprecision(3) << float(total2)/count << endl;
	  outFile << "Average for test 3: " << fixed << setprecision(3) << float(total3)/count << endl;
	}
      else 
	{
	  outFile << "There were no numbers in the file.";
	}
      inFile.close();
	}
  outFile.close();
  cout << "The program has run!" << endl;
  cout << "Go to emacs result.dat to see the results. " << endl;
  return 0;
}
