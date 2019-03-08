//final.C
//CS 111
//Implemented by DAG
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

//Structure for customers info
struct customer
{
  string name;
  string address;
  string city;
  string state;
  string  zip;
  string telephone_Number;
  string lastPaymentDate;
  double accountBalance;
};

//function prototypes
void readData(customer[],int);
void updateCustomer(customer[],string,int);
void display(customer[],int);
void searchCustomer(customer[],string,int);
void sortByBalance(customer[],int);
void sortByName(customer[],int);
int compareCustomer(customer[],string,string,int);

int main()
{
  //Constant for the number of accounts
  const int NUM_ACCOUNTS = 10;

  //Array of Customer structures
  customer Customers[NUM_ACCOUNTS];
  string name,firstName,secondName;

  while(1)
    {//Give a "menu" to choose from
      cout<<"\nPress 1 to load customer data\n"
          <<"Press 2 to edit customer info\n"
          <<"Press 3 to display all customers\n"
          <<"Press 4 to search customers\n"
          <<"Press 5 to sort according to balance\n"
          <<"Press 6 to sort according to name\n"
          <<"Press 7 to compare to customer\n"
          <<"Press 8 to exit.\n";
      int choice;
      cout << "\nOption: ";
      cin >> choice;//Get user input
      switch(choice)
        {
        case 1://Call read data
	  readData(Customers,NUM_ACCOUNTS);
	  break;
        case 2:
	  cout << "\nEnter name of customer : ";
	  cin >> name;//Get name from user
	  //Call update function
	  updateCustomer(Customers,name,NUM_ACCOUNTS);
	  break;
        case 3://Call display function for all customers
	  display(Customers,NUM_ACCOUNTS);
	  break;
        case 4:
	  cout << "\nEnter name of customer : ";
	  cin >> name;//Get name from user
	  //Call search to look for certain customer
	  searchCustomer(Customers,name,NUM_ACCOUNTS);
	  break;
        case 5://call sort by balance 
	  sortByBalance(Customers,NUM_ACCOUNTS);
	  break;
        case 6://Call sort by name
	  sortByName(Customers,NUM_ACCOUNTS);
	  break;
        case 7:
	  cout << "\nEnter name of customer 1: ";
	  cin >> firstName;
	  cout << "\nEnter name of customer 2: ";
	  cin >> secondName;
	  //call the compare function pass the two customer names
	  compareCustomer(Customers,firstName,secondName,NUM_ACCOUNTS);
	  break;
        case 8:
	  return 0;
        }
    }
}

//Function for reading data into the array of customers declared earlier. 
//Passes the array and the size
void readData(customer arr[], int size)
{
  ifstream input;//For reading off the file
  input.open("customers.txt");//Open file
  int i = 0;//use as a counter
  cout << "\nReading customer data...\n ";
  //As long as there is input and does not exceed array size
  while(input && i < size)
    {//Fill in information in the array of customers
      input >> arr[i].name 
	    >> arr[i].address 
	    >> arr[i].city
	    >> arr[i].state
	    >> arr[i].zip
	    >> arr[i].telephone_Number
	    >> arr[i].lastPaymentDate
	    >> arr[i].accountBalance;
      i++;//Increment counter
    }
}

//Function for updating a customers info in the array
void updateCustomer(customer arr[],string name,int size)
{
  int i;
  for(i = 0; i < size; i++)
    {
      if(arr[i].name.compare(name) == 0)break;
    }
  if(i!=size)
    {
      cout<<"Enter updates : "<<endl;
      cout<<"Address : ";
      cin>>arr[i].address;
      cout<<"City    : ";
      cin>>arr[i].city;
      cout<<"State   : ";
      cin>>arr[i].state;
      cout<<"Zip     : ";
      cin>>arr[i].zip;
      cout<<"Telephone: ";
      cin>>arr[i].telephone_Number;
      cout<<"Last payment date : ";
      cin>>arr[i].lastPaymentDate;
      cout<<"Account Balance : ";
      cin>>arr[i].accountBalance;
    }
  else
    {
      cout<<"No customer exist by this name"<<endl;
    }
}

void display(customer arr[],int size)
{
  cout<<"*************************Customer info***********************"<<endl;
  for(int i=0;i<size;i++)
    {
      cout<<"Name    : "<<arr[i].name<<endl
	  <<"Address : "<<arr[i].address<<endl
	  <<"City    : "<<arr[i].city<<endl
	  <<"State   : "<<arr[i].state<<endl
	  <<"Zip     : "<<arr[i].zip<<endl
	  <<"Telephone: "<<arr[i].telephone_Number<<endl
	  <<"Last payment date : "<<arr[i].lastPaymentDate<<endl
	  <<"Account Balance : "<<arr[i].accountBalance<<endl<<endl;
    }
}

void searchCustomer(customer arr[],string name,int size)
{
  int count=0;
  for(int i=0;i<size;i++)
    {
      if(arr[i].name.find(name)<arr[i].name.length())
        {
	  cout<<"Name    : "<<arr[i].name<<endl
	      <<"Address : "<<arr[i].address<<endl
	      <<"City    : "<<arr[i].city<<endl
	      <<"State   : "<<arr[i].state<<endl
	      <<"Zip     : "<<arr[i].zip<<endl
	      <<"Telephone: "<<arr[i].telephone_Number<<endl
	      <<"Last payment date : "<<arr[i].lastPaymentDate<<endl
	      <<"Account Balance : "<<arr[i].accountBalance<<endl<<endl;
	  count++;
        }
    }
  if(count==0)
    cout<<"No customer found by name : "<<name<<endl;
}

void sortByBalance(customer arr[],int size)
{
  int i,j, minIndex;
  customer minCustomer;
  
  for (i = 0; i < (size - 1); i++) 
    {
      minIndex = i;       
      minCustomer = arr[i];       
      for(int j = i + 1; j < size; j++) 
	{          
	  if (arr[j].accountBalance < minCustomer.accountBalance) 
	    {             
	      minCustomer = arr[j];             
	      minIndex = j;
	    }
	}     
      arr[minIndex] = arr[i];     
      arr[i] = minCustomer; 
    }
  
  ofstream output;
  output.open("balances.txt");
  for(i=0;i<size;i++)
    {
      output<<arr[i].name<<" "<<arr[i].address<<" "<<arr[i].city
	    <<" "<<arr[i].state<<" "<<arr[i].zip
	    <<" "<<arr[i].telephone_Number<<" "
	    <<arr[i].lastPaymentDate<<" "<<arr[i].accountBalance<<endl;
    }
  output.close();
}
void sortByName(customer arr[],int size)
{
  int i,j, minIndex;
  customer minCustomer;
  
  for (i = 0; i < (size - 1); i++)  
    {  
      minIndex = i; 
      minCustomer = arr[i];   
      for(int j = i + 1; j < size; j++) 
	{       
	  if (arr[j].name < minCustomer.name)   
	    {             minCustomer = arr[j];   
	      minIndex = j; 
	    }
	}
      arr[minIndex] = arr[i];  
      arr[i] = minCustomer; 
    }
  
  ofstream output;
  output.open("names.txt");
  for(i=0;i<size;i++)
    {
      output<<arr[i].name<<" "<<arr[i].address
	    <<" "<<arr[i].city<<" "<<arr[i].state<<" "
	    <<arr[i].zip<<" "<<arr[i].telephone_Number
	    <<" "<<arr[i].lastPaymentDate<<" "
	    <<arr[i].accountBalance<<endl;
    }
  output.close();
}

int compareCustomer(customer arr[],string name1,string name2,int size)
{
  int i=0,j=0;
  bool found = false;

  while (i<size && !found)
    {
      if(arr[i].name==name1)
	found = true;
      else
	i++;
    }

  if(!found)
    cout<<name1<< "was not found in the list!" << endl;

  found = false;
  while (j<size && !found)
    {
      if(arr[j].name==name2)
	found = true;
      else
	j++;
    }

  if(!found)
    cout<<name2<< "was not found in the list!" << endl;

  if(name1>name2)
    {
      arr[j].address=arr[i].address;
      return arr[j].address.length();
    }
  else
    {
      arr[i].address=arr[j].address;
      return arr[j].address.length();
    }


}
