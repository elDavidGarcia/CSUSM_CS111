/********************************************************************************/
/*PURPOSE: Makes a menue where the user choses what to do.                      */
/*IMPLEMENTED BY: DAG                                                           */
/*DATE: 12/2/15                                                                 */
/*USER INFORMATION: The user puts inputs a choice.                              */
/*IMPLEMENTATION METHOD: The program gets a choice and gives the user other     */
/*                       choices to choose from.                                */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and subparts.  */
/********************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 10;

struct cst //make the struct.
{
  string name;
  string address;
  string city;
  string state;
  int zip;
  long long int phone;
  int pay;
  double balance;
};

void readInfo(cst ar[]);
void changeAccount(cst ar[]);
void displayInfo(cst ar[]);
void searchAr(cst ar[], string);
void sortDescending(cst ar[]);
void sortDescendingName(cst ar[]);
void compareCustomers(string, string);

int main()
{
  int ans;
  cst ar[SIZE];
  string name, name1, name2;
  readInfo(ar);
  cout << "Menu: " << endl << endl;
  cout << "1. Read customers' info from file to the array. " << endl;
  cout << "2. Change account info from a customer. " << endl;
  cout << "3. Display all data stored in the array. " << endl;
  cout << "4. Search for a particular customer's account. " << endl;
  cout << "5. Sort the structure array according to balances in descending order. " << endl;
  cout << "6. Sort structured array according to name in accending order. " << endl;
  cout << "7. Compare two customer's names, and replace address od smaller with the larger. " << endl;
  cout << "8. Exit the program. " << endl;
  
  do{
    cout << endl << "Please pick a choice by entering a number (1-8): ";
    cin >> ans;
    
    
    switch(ans)
      {
      case 1: cout << "The info in the file has been read. \n";
	break;
      case 2: changeAccount(ar);
	break;
      case 3: displayInfo(ar);
	break;
      case 4: 
	cout << "Enter a name: ";
	cin >> name;
	searchAr(ar, name);
	break;
      case 5: sortDescending(ar);
	break;
      case 6: sortDescendingName(ar);
	break;
      case 7: 
	cout << "Enter two names using a space in between \n";
	cin >> name1 >> name2;
	//compareCustomers(name1, name2);
	break;
      case 8: cout << "Program will exit \n";
	break;
      default: cout << "You did not enter a number 1-8 \n";
      }
  }while(ans != 8);
    
  return 0;
}

void readInfo(cst ar[])
{
  ifstream fin;
  int i = 0;
  
  fin.open("customers.txt");
  
  if(!fin)
    cout << "Could not open File \n";
  do
    {
      fin >> ar[i].name 
	  >> ar[i].address 
	  >> ar[i].city 
	  >> ar[i].state 
	  >> ar[i].zip 
	  >> ar[i].phone 
	  >> ar[i].pay 
	  >> ar[i].balance;
      i++;
    }while(fin && i < SIZE);
  fin.close();
}

void changeAccount(cst ar[])
{
  string key;
  int index = 0, i = -1;
  bool found = false;
  
  cout << "Enter the employee name (use _ instead of space): ";
  cin >> key;
  while(index < SIZE && !found)
    {
      if (ar[index].name == key)
	{
	  found = true;
	  i = index;
	}
      index++;
    }
  if(!found)
    cout << "There is no such employee! \n";
  else 
    {
      cout << "Enter the new information for " << ar[i].name << "(use _ instead of space). \n";
      cout << "Address: ";
      cin >> ar[i].address;
      cout << "City: ";
      cin >> ar[i].city;
      cout << "State: ";
      cin >> ar[i].state;
      cout << "Zip: ";
      cin >> ar[i].zip;
      cout << "Phone: ";
      cin >> ar[i].phone;
      cout << "Pay: ";
      cin >> ar[i].phone;
      cout << "Balance: ";
      cin >> ar[i].balance;
    
  cout << ar[i].name
       << " " << ar[i].address
       << " " << ar[i].city
       << " " << ar[i].state
       << " " << ar[i].zip
       << " " << ar[i].phone
       << " " << ar[i].pay
       << " " << ar[i].balance << endl;
    }
}

void displayInfo(cst ar[])
{
  cout << left << setw(15) << "Name: "
       << setw(19) << "Address: "
       << setw(11) << "City: "
       << setw(8) << "State: "
       << setw(6) << "Zip: "
       << setw(11) << "Phone: "
       << setw(9) << "Pay: "
       << setw(9) << "  Balance: " << endl;
  for(int n = 0; n < SIZE; n++)
    {
      cout << left << setw(15) << ar[n].name 
           << setw(19) << ar[n].address 
           << setw(11) << ar[n].city 
           << setw(8) << ar[n].state 
           << setw(6) << ar[n].zip 
           << setw(11) << ar[n].phone 
           << right << setw(9) << ar[n].pay 
           << right << setw(10) << ar[n].balance << endl;
    }
}

void searchAr(cst ar[], string name)
{
  int count = 0, i = -1;
  for(count; count < SIZE; count ++)
    {
      if(ar[count].name == name)
	i = count;
    }
   if(i < SIZE || i >= 0) 
    cout << ar[i].name
	 << " " << ar[i].address
	 << " " << ar[i].city
	 << " " << ar[i].state
	 << " " << ar[i].zip
	 << " " << ar[i].phone
	 << " " << ar[i].pay
	 << " " << ar[i].balance << endl;
  else
    cout << "Could not find employee! \n";
}

void sortDescending(cst ar[])
{
  ofstream fout;
  int start, minIdx;
  double minVal;
  fout.open("balances.txt");
  fout << left << setw(15) << "Name: "
       << setw(19) << "Address: "
       << setw(11) << "City: "
       << setw(8) << "State: "
       << setw(6) << "Zip: "
       << setw(11) << "Phone: "
       << setw(9) << "Pay: "
       << setw(9) << "  Balance: " << endl;
  for(start = 0; start < (SIZE - 1); start++)
    {
      minIdx = start;
      minVal = ar[start].balance;
      for(int index = start + 1; index < SIZE; index++)
        {
          if(ar[index].balance > minVal)
            {
	      minVal = ar[index].balance;
              minIdx = index;
            }
	}
      ar[minIdx].balance = ar[start].balance;
      ar[start].balance = minVal;
    }
  for(int n = 0; n < SIZE; n++)
    {
      fout << left << setw(15) << ar[n].name
	   << setw(19) << ar[n].address
	   << setw(11) << ar[n].city
	   << setw(8) << ar[n].state
	   << setw(6) << ar[n].zip
	   << setw(11) << ar[n].phone
	   << right << setw(9) << ar[n].pay
	   << right << setw(10) << ar[n].balance << endl;
    }
  fout.close();
  cout << "The information has been sorted! View it at: balances.txt \n";
}

void sortDescendingName(cst ar[])
{
  ofstream fout;
  int start, minIdx, n = 0;
  string minVal;
  fout.open("names.txt");
  
  fout << left << setw(15) << "Name: "
       << setw(19) << "Address: "
       << setw(11) << "City: "
       << setw(8) << "State: "
       << setw(6) << "Zip: "
       << setw(11) << "Phone: "
       << setw(9) << "Pay: "
       << setw(9) << "  Balance: " << endl;
  for(start = 0; start < (SIZE - 1); start++)
    {
      minIdx = start;
      minVal == ar[start].name;
      for(int index = start + 1; index < SIZE; index++)
        {
	  if(ar[index].name < minVal )
            {
              minVal = ar[index].name;
              minIdx = index;
            }
        }
      ar[minIdx].name = ar[start].name;
      ar[start].name = minVal;
      //}
  
  //for(int n = 0; n < SIZE; n++)
      //{
      fout << left << setw(15) << ar[n].name
           << setw(19) << ar[n].address
           << setw(11) << ar[n].city
           << setw(8) << ar[n].state
           << setw(6) << ar[n].zip
	   << setw(11) << ar[n].phone
           << right << setw(9) << ar[n].pay
           << right << setw(10) << ar[n].balance << endl;
      n++;
      }
  
  fout.close();
  cout << "The information has been sorted! View it at: names.txt \n";
}

