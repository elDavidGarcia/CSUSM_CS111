//distance.C
//CS 111
//Implemented by DAG
//Simple program to solve distance between two
//given points
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
  double pt1x, pt1y,  length1, length2, pt2x, pt2y, distance;

  //Get user input
  cout << "Enter X for point 1: ";
  cin >> pt1x; 
  cout << "Enter Y for point 1: " ; 
  cin >> pt1y;

  cout << "\nEnter X for point 2:";
  cin >> pt2x; 
  cout << "Enter Y for point 2 ";
  cin >> pt2y;
  
  // Calculate the distance.
  length1 = pt2x - pt1x;
  length2 = pt2y - pt1y;
  distance = sqrt((pow(length1, 2)) + (pow(length2, 2)));

  // Display the distance. 
    cout << "\nThe distance is: " << distance << endl;
  return 0;
}
  
