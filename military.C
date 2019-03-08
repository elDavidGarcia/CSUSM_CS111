//This prpgram determines if a person can enter the military.
#include <iostream>
#include <string>
using namespace std;

void getInfo(string &name, char &gender, int &age);
bool verifyElgibility(char gender, int age);
void printLetter(bool elgile, string name);

int main()
{
  string name;
  char gender;
  int age;
  bool elgible;

  getInfo(name, gender, age);
  elgible = verifyElgibility(gender, age);
  printLetter(elgible, name);
  return 0;
}

void getInfo(string &name, char &gender, int &age)
{
  cout << "Enter your name: ";
  getline(cin, name);
  
  cout << "Enter gender (Enter M for male or F for female): ";
  cin >> gender;

  cout << "Enter age: ";
  cin >> age;
}

bool verifyElgibility(char gender, int age)
{
  bool verify;
  if (((gender == 'M')||(gender == 'm'))&&(age >= 18))
    {
    verify = true;
    }
  else 
    {
      verify = false;
    }
  return verify;
}

void printLetter(bool elgible, string name)
{
  if (elgible == true)
    cout << "Dear " << name << ", please join the military!" << endl;
  else 
    cout << "Thank you for applying. " << endl;
}
