/**************************************************************************/
/*PURPOSE: The program counts how many numbers there are in a file, sums  */
/*them, and gives the average.                                            */
/*IMPLEMENTED BY: David Garcia                                            */
/*DATE: 10/14/15                                                          */
/*USER INFORMATION: The user inputs numbers in the in file.               */
/*IMPLEMENTATION METHOD: The program will calculate the how many numbers  */
/* are in a file, the sum, and average.                                   */
/*OVERVIEW OF SUBPARTS: The program consist of only the main function.    */
/**************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  //Declare the variables.
  int x, count = 0, sum = 0;
  ifstream inFile;
  ofstream outFile;

  //Declare the in and out files.
  inFile.open("Random.txt");
  outFile.open("output.txt");

  //Make an if statement in case there is no file.
  if(!inFile)
    {
      cout << "Could not open file! ";
    }
  else
    {
      //Make a looooooop!
      inFile >> x;
      while (inFile)
        {
          count++;
          sum = x + sum;
          inFile >> x;
        }
      //Export to the out file.
      outFile << "There are " << count << " numbers in the file! " << endl;
      outFile << "The sum of all " << count << " numbers is " << sum << "! " << endl;
      outFile << "The average of all " << count << " numbers is " << (double)sum/count << "! " << endl;
      inFile.close();
      //Tell the user the job is done!
      cout << "The program ran successfully! " << endl;
      cout << "View the result  at: emacs output.txt " << endl;
    }
  outFile.close();
  return 0;
}
