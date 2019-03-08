//Header goes here.
#include <iostream>
#include <iomanip>
using namespace std;

void  getCustomerInfo(int &account, int &month, int &day, int &year, char &county);
double getItemsInfo(double &tsale, double &tweight);
double calcDiscount(double tsale, int month);
double calcSalesTax(char county, double discount, double tsale);
double calcShipping(double tweight);
void outputInvoice(int account, int month, int day, int year, char county, double tsale, double discount, double tax, double shipping);

int main()
{
  int account, month, day, year;
  char county;
  double tsale, tweight, discount, tax, shipping;
  string countyName;
  getCustomerInfo(account, month, day, year, county);
  getItemsInfo(tsale, tweight);
  discount = calcDiscount(tsale, month);
  tax = calcSalesTax(county, discount, tsale);
  shipping = calcShipping(tweight);
  outputInvoice(account, month, day, year, county, tsale, discount, tax, shipping);
}

void getCustomerInfo(int &account, int &month, int &day, int &year, char &county)
{
  cout << "Enter the account number: ";
  cin >> account;
  cout << "Enter the month, day, and year using namespace in between." << endl;
  cin >> month >> day >> year;
  cout << "Enter county S for San Diego, O for Orange County, or L for Los Angeles" << endl;
  cin >> county;
  while((account < 0)||(month <= 0)||(day <= 0)||(year <= 0))
    {
      cout << "One or more of the information you have entered is invalid! Please re-enter: " << endl;
      cout << "Account number: ";
      cin >> account;
      cout << "Month, day, and year: " << endl;
      cin >> month >> day >> year;
      cout << "County S for San Diego, O for Orange County, or L for Los Angeles" << endl;
      cin >> county;
    }
}

double getItemsInfo(double &tsale, double &tweight)
{
  char ans;
  double price, weight, tweight1 = 0;
      cout << "Would you like to order an item? Enter Y or N: ";
      cin >> ans;
      while ((ans == 'Y')||(ans == 'y'))
     {
      cout << "Enter a price: ";
      cin >> price;
      cout << "Enter a weight: ";
      cin >> weight;
      while((price < 0)||(weight <= 0))
	{
	  cout << "Either the price or weight you have entered is invalid! Please re-enter, " << endl;
	  cout << "Price: ";
	  cin >> price;
	  cout << "Weight: ";
	  cin >> weight;
	}
      tsale = price + tsale;
      tweight1 = weight + tweight1;
      cout << "Would you like to order another item? Enter Y or N: ";
      cin >> ans;
     }
      tweight = tweight1;
}

double calcDiscount(double tsale, int month)
{
  double discount; 
  const double DISC1 = 0.05;
  const double DISC2 = 0.10;
  const double DISC3 = 0.15;
  if((month >= 0)&&(month <= 5))
    {
      discount = tsale * DISC1;
    }
  else if((month >= 6)&&(month <= 8))
    {
      discount = tsale * DISC2;
    }
  else if((month >= 9)&&(month <= 12))
    {
      discount = tsale * DISC3;
    }
  return discount;
}

double calcSalesTax(char county, double discount, double tsale)      
{
  const double SD = 0.0775;
  const double OC = 0.0775;
  const double LA = 0.0825;
  double tax;
  if((county == 'S')||(county == 's'))
    {
      tax = (tsale-discount)*SD;
    }
  else if((county == 'O')||(county == 'o'))
    {
      tax = (tsale-discount)*OC;
    }
  else if((county == 'L')||(county == 'l'))
    {
      tax = (tsale-discount)*LA;
    }
  return tax;
}

double calcShipping(double tweight)
{
  double shipping, shipping1, shipping2, shipping3;
  shipping1 = 5.00;
  shipping2 = shipping1 + ((tweight-25)*0.10);
  shipping3 = shipping1 + 2.50 + ((tweight-50)*0.07);
  if((tweight > 0)&&(tweight <= 25))
    {
      shipping = shipping1;
    }
  else if((tweight >= 26)&&(tweight <= 50))
    {
      shipping = shipping2;
    }
  else if(tweight > 50)
    {
      shipping = shipping3;
    }
  return shipping;
}

void outputInvoice(int account, int month, int day, int year, char county, double tsale, double discount, double tax, double shipping)
{  
  double total;

  total = (tsale-discount)+tax+shipping;

  cout << endl;
  cout << left << setw(25) << "ACCOUNT NUMBER " << right << setw(12) << "COUNTY " << endl;
  if((county == 'S')||(county == 's'))
    cout << left << setw(25) <<  account << right << setw(12) << "San Diego " << endl;
  else if((county == 'O')||(county == 'o'))
    cout << left << setw(25) <<  account << right << setw(12) << "Orange County " << endl;
  else if((county == 'L')||(county == 'l'))
    cout << left << setw(25) <<  account << right << setw(12) << "Los Angeles " << endl;
  cout << endl;
  cout << "DATE OF SALE: " << month << "/" << day << "/" << year << endl;
  cout << endl;
  cout << left << setw(25) << "TOTAL SALE AMOUNT: " << "$" << fixed << setprecision(2) << right << setw(10) << tsale << endl;
  cout << left << setw(25) << "DISCOUNT: " << "$" << fixed << setprecision(2) << right << setw(10) << discount << endl;
  cout << left << setw(25) << "SALES TAX: " << "$" << fixed << setprecision(2) << right << setw(10) << tax << endl;
  cout << left << setw(25) << "SHIPPING: " << "$" << fixed << setprecision(2) << right << setw(10) << shipping << endl;
  cout << left << setw(25) << "Total: " << "$" << fixed << setprecision(2) << right << setw(10) << total << endl;
}
