//second_array.C
//CS111
//Implemented by DAG
//Program makes simple array out of numbers given by user.
//Asks user for a number and searches for it in the array.
//Returns true or false. Sorts array from smallest to biggest
//and displays it one last time.

#include <iostream>
using namespace std;

const int SIZE = 5; //Size to be used in array

//Function Prototypes
void fillArray(int ar[]);
void printArray(int ar[]);
int findKey(int ar[], int);
void sortArray(int ar[]);

int main()
{
  int ar[SIZE], key, ans = 0;
  fillArray(ar);//Fill the array
  cout << "\nThe numbers you have entered are: \n";
  printArray(ar);//Display array
  cout << "\nEnter a key: ";
  cin >> key;
  ans = findKey(ar, key);//Look for key in the array
  if(ans == -1)//key was not found in the array
    cout << key << " was not found in the array. \n";
  else//Key was found give the array index it was found
    cout << key << " was found in the array in index " << ans << endl << endl;
  sortArray(ar);//Sort array from smallest to greatest
  printArray(ar);//Print one last time
  return 0;
}

//Function fills array with user input
void fillArray(int ar [])
{
  int i = 0, num;
  //Ask user to fill the array 
  for(i; i < SIZE; i++)
    {
      cout << "Enter a number: ";
      cin >> num;
      ar[i] = num;//Enter input in array slot
    }
}

//Function displays array
void printArray(int ar [])
{
  int i = 0;
  //Go through each index and display
  for(i; i < SIZE; i++)
    {
      cout << ar[i] << " ";
    }
  cout << endl;
}

//Function looks for the user given key
int findKey(int ar[], int key)
{
  int index = 0;
  int position = -1;
  bool found = false;

  //Look through every index for key
  while(index < SIZE && !found)
    {
      if (ar[index] == key)
	{//key was found
	  found = true;
	  position = index;//store index
	}
      index++;//increment index
    }
  return position;//return -1 or index key was found
}

//Function to sort the array from smallest to greatest
void sortArray(int ar[])
{
  int start, minIdx, minVal;

  //Start at index 0 and go to last index
  for(start = 0; start < (SIZE - 1); start++)
    {
      minIdx = start;//store index for smallest value
      minVal = ar[start];//store the smallest value
      //Compare the minIndex value to the rest of the array
      for(int index = start + 1; index < SIZE; index++)
	{
	  //If there is a smaller value 
	  if(ar[index] < minVal)
	    {
	      minVal = ar[index];//Store the new smaller value
	      minIdx = index;//Store its index
	    }
	}
      //Swap the two
      ar[minIdx] = ar[start];
      ar[start] = minVal;
    }
}
