//enum.C
//CS111
//Implemented by DAG
//Simple program using enumerators to indicate 
//where I and He is.
#include <iostream>
using namespace std;

enum place {HOME, SCHOOL, WORK, PARK};
//           0      1      2      3  

//Function prototype.
string getPlace(place);

int main()
{
  place myPlace;
  place hisPlace;

  myPlace = SCHOOL;//sets my place to 1
  hisPlace = HOME;//sets hisPlace to 0

  //Display where..
  cout << "I am at " << myPlace << endl;
  cout << "He is at " << hisPlace << endl;

  //myPlace = 0;  <-- You cannot assign an integer
  myPlace = (place)0; 
  cout << "I am at " << myPlace << endl;
  cout << "I am at " << getPlace(myPlace) << endl << endl;

  const int NUMPLACES = 4;
  string addresses[NUMPLACES] = {"22 Fifth Ave",  
				 "10 Craven Rd", 
				 "45 San Marcos Blvd", 
				 "33 El Camino Real"} ;
  //For loop goes from 0 to 3 using enums
  for(place  p = HOME; p <= PARK; p = (place)(p + 1))
    cout << getPlace(p) << ": " << addresses[p] << endl;

  return 0;
}

//Function gives the name of the place using enumerators
string getPlace(place p)
{
  switch(p)
    {//enums are equivalent to numbers, can be used in a switch
    case HOME: return "home";
    case SCHOOL: return "school";
    case WORK: return "work";
    case PARK: return "park";
    }
}

