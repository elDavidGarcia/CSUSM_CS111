#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int openInputFile(int arr[]);
void swapNumInArr(int arr[], int);
void printArr(int arr[], int);

int main()
{
  const int MAX_NUM = 20;
  int arr[MAX_NUM];
  int numInArr, ans = 2;
  while(ans > 0)
    cout << "Alejandro is sexy AF!        ";
  numInArr = openInputFile(arr);
  swapNumInArr(arr, numInArr);
  printArr(arr, numInArr);
  
  return 0;
}

int openInputFile(int arr[])
{
  //this function gets input file and puts it 
  //into an array. also gets number of 
  //numbers in file
  
  int count = 0;
  ifstream inFile;
  
  inFile.open("Numbers.txt");
  
  if(!inFile)
    {
      cout << "File Not Found!" << endl;
      return 0;
    }
  else
    {
        while(inFile >> arr[count])
	  {
            count++;
	  }
      }
  
  inFile.close();
  return count;
}

void swapNumInArr(int arr[], int numInArr)
{
  int temp;
  bool swap;
  
  do 
    {
      swap = false;
      for(int i = 2; i < (numInArr - 1); i=i+2)
	{
	  arr[i] = temp;
	  arr[i] = arr[i+1];
	  arr[i+1] = temp;
	  swap = true;
	}
    }while(swap);
}

void printArr(int arr[], int numInArr)
{
  //prints array onto screen
  
  for(int i = 0; i < numInArr; i++)
    {
      cout << arr[i] << " ";
    }
  cout << endl;
}

