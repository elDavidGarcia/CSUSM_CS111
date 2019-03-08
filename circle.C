/********************************************************************************/
/*PURPOSE: Gets radius and calculates area, diameter, and circumference.        */
/*IMPLEMENTED BY: DAG                                                  */
/*DATE: 12/7/15                                                                 */
/*USER INFORMATION: The user puts inputs radius.                                */
/*IMPLEMENTATION METHOD: The program gets a radius from user and calculates the */
/*                       area, diameter, and circumference of a circle.         */
/*OVERVIEW OF SUBPARTS: The program consist of the main function and subparts.  */
/********************************************************************************/
#include <iostream>
using namespace std;

class circle//initialize circle class
{
private://only functions in circle can call privite
  double radius;
  double pi;
public://functions to interact with circle object
  circle();//constructor
  circle(double r);//constructor with given radius 
  void setRadius(double newR);//Set a new radius
  double getRadius();//returns object's radius
  double getArea();//returns object's Area
  double getDiameter();//returns object's diameter
  double getCircumference();//returns object's circumference
};

//Constructs a circle object with no given parameters
circle::circle()
{
  radius = 0.0;//Radius of new circle object
  pi = 3.14;
}

//Constructs a circle with a given radius
circle::circle(double r)
{
  radius = r;//Radius of new circle given by parameter
  pi = 3.14;
}

//Changes a circle object's radius with that of the parameters
void circle::setRadius(double newR)
{
  radius = newR;
}

//Returns a circle object's radius 
double circle::getRadius()
{
  return radius;
}

//Returns a circle object's Area
double circle::getArea()
{//calculate area with object's radius and pi
  return pi*radius*radius;
}

//Returns a circle object's diameter
double circle::getDiameter()
{//calculate diameter with object's radius
  return radius*2;
}

double circle::getCircumference()
{//Calculate circumference w/ objects radius and pi
  return pi*radius*2;
}

int main()
{
  circle c1; //Construct a circle object with no given parameters 
  double ans;
  cout << "Enter a radius: ";
  cin >> ans;
  c1.setRadius(ans);//set new radius to given input
  //Display the circle object's properties
  cout << "Circle's radius: " << c1.getRadius() << endl;
  cout << "Circles's area: " << c1.getArea() << endl;
  cout << "Circle's diameter: " << c1.getDiameter() << endl;
  cout << "Circle's circumference: " << c1.getCircumference() << endl; 
  return 0;
}
