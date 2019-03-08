//array.C
//CS111
//Implemnted by DAG
//Very simple array program
//fills array, looks for the biggest number, 
//multiplies the array's contents by two, 
// and displays the new numbers

#include <iostream>
using namespace std;

int main()
{
  const int SIZE = 5;//arry size
  int array[SIZE];//initialize array
  int highest, i = 0, count;
 
 //Fill the array
  for(i = 0; i < SIZE; i++)
    {
      cout << "Enter a number: ";
      cin >> array[i];
    }

  highest = array[0];//set highest to first number in array
  //Compare current highest to the rest of the array
  for(count = 1; count < SIZE; count++)
    {
      if(array[count] > highest)
	highest = array[count];
    }

  //Make the numbers in the array 2 times bigger
  for(i = 0; i < SIZE; i++)
    array[i] = array[i]*2;
  
  cout << "\nThe highest number is " << highest << endl;
  cout << "\nThe new numbers in the array are: ";
  //Display the new array
  for(i = 0; i < SIZE; i++)
    cout << " " << array[i];
  cout << endl;
  return 0;
}
