//Header 
#include <iostream>
#include <string>
using namespace std;

void function1(const char source[], char dest[]);

int main()
{
  char st[10] = "Hello";
  char st2[20] = "University";
  function1(st, st2);
  cout << st2 << endl;
  return 0;
}

void function1(const char source[], char dest[])
{
  int i = 0;
  for(i; source[i] != '\0'; i++)
    {
      dest[i] = source[i];
    }
  dest[i] = '\0';
}
