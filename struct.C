//Header goes here
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX = 100;
struct emp
{
  string fName;
  string lName;
  char gender;
  double pay;
  int empID;
  int age;
};

int readData(emp ar[]);
void findMale(emp ar[], int);
void findEmployee(emp ar[], int);
emp findOldest(emp ar[], int);
void printEmployee(emp oldest);

int main()
{
  int number; 
  emp ar[MAX], oldest;

  number = readData(ar);
  findMale(ar, number);
  cout << endl;
  cout << "There are "  << number << " employees " << endl << endl;
  findEmployee(ar, number);
  oldest = findOldest(ar, number);
  cout << endl << "The Oldest person is " << oldest.fName << endl;
  printEmployee(oldest);
  cout << endl << "Open maleOut.dat to see male employees " << endl;
  return 0;
}

int readData(emp ar[])
{
  ifstream inFile;
  int num = 0;
  
  inFile.open("employees.dat");

  if(!inFile)
    cout << "Could not open file! " << endl;

  inFile >> ar[num].fName >> ar[num].lName >> ar[num].gender >> ar[num].pay >> ar[num].empID >> ar[num].age;
  while(inFile && (num < MAX))
    {
      num++;
      inFile >> ar[num].fName >> ar[num].lName >> ar[num].gender >> ar[num].pay >> ar[num].empID >> ar[num].age;
    }
  inFile.close();
  return num;
}

void findMale(emp ar[], int number)
{
  ofstream outFile;
  outFile.open("maleOut.dat");
  outFile << left << setw(7) << "ID: " << setw(13) << "First Name: " << setw(13) << "Last Name: " << endl << endl;
  for(int i = 0; i < number; i++)
    {
      if(ar[i].gender == 'M')
	outFile << left << setw(7) << ar[i].empID 
		<< setw (13) << ar[i].fName 
		<< setw(13) << ar[i].lName << endl;
    }
  outFile.close();
}

void findEmployee(emp ar[], int number)
{
  bool found = false;
  int ans;
  cout << "Enter an employee ID: ";
  cin >> ans;
  for(int i = 0; !found && i < number; i++)
    {
      if(ar[i].empID == ans)
	{
	  found = true;
	  cout << ar[i].fName << " " << ar[i].lName << "'s ID matches " << ar[i].empID << endl;
	}
    }
  if(!found)
    cout << "There is no employee with " << ans << " as an ID! " << endl;
}

emp findOldest(emp ar[], int number)
{
  int count = 0, highestAge, highestCount = 0;
  highestAge = ar[0].age;
  for(count = 1; count < number; count++)
    {
      if(ar[count].age > highestAge)
	{
	  highestAge = ar[count].age;
	  highestCount = count;
	}
    }

  return ar[highestCount];
  
}
  
void printEmployee(emp oldest)
{
  cout << left << setw(10) << oldest.fName 
       << setw(10) << oldest.lName 
       << setw(6) << oldest.gender  
       << setw(6) << oldest.pay 
       << setw(6) << oldest.empID 
       << setw(6) << oldest.age << endl;
}
