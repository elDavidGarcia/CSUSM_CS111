//car.C
//CS111
//Implemented by DAG
//Simple progaram that reads from an input file and 
//outputs to an ouput file.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  double mpg, tavg = 0;
  int miles,gallons, count = 0,tmiles = 0,tgas = 0;
  string cn;
  ifstream inFile;//to read file input
  ofstream outFile;//to output to a file

  inFile.open("car.dat");//read from car.dat
  outFile.open("carout.dat");//output to carout.dat

  if (!inFile)//file was not found
    cout << "Cannot open file" << endl;
  
  else
    {//Set up the column names in output file
      outFile << left << setw(15) << "Model Name: " 
	      << right << setw(15) << "Miles Driven:" 
	      << right << setw(25) << "Gallons of Gas Used:" 
	      << right << setw(10) << "MPG:" << endl;

      inFile >> cn >> miles >> gallons;//read input from file once

      while (inFile)
        {
	  mpg =(double)miles/gallons;//Calculate and store mpg
	  tmiles = miles + tmiles;//accumulate miles
	  tgas = gallons + tgas;//accumulate gas 
	  tavg = mpg + tavg;//accumulate mpg
	  outFile << fixed << setprecision(2) 
		  << left << setw(15) << cn 
		  << right << setw(15) << miles 
		  << right << setw(25) << gallons 
		  << right << setw(10) << mpg << endl;
	  count++;//Increment count, used later for average
	  inFile >> cn >> miles >> gallons;//read next inputs
        }

      if (count != 0)//There was something in the file
	{//Display total...
	  outFile << "\nTotal Miles Driven: " << tmiles << " miles" << endl;
	  outFile << "Total Gallons of Gas Used: " << tgas << " gallons" << endl;
	  outFile << "Average MPG: " << (double)tavg/count << " miles per gallon" << endl;
	}
      else//Nothing to display
        {
          outFile << "There were no numbers in the file.";
        }
      inFile.close();//Close input file
    }
  outFile.close();//Close output file
  cout << "The program has run!" << endl;
  cout << "Go to carout.dat to see the results. " << endl;
  return 0;
}

