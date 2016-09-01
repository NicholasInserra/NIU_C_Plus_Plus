
/***********************************************************
CSCI 689 Assignment 10

Progammer: Nick Inserra
Section: 1
Date Due: 4/20  

File Name: Shape3.cc

Purpose: Hold the implemntation for a series of 3d shapes all
         shapes are ultimatly derived from shape base class
         however none of them are directly derived from shape
************************************************************/ 








#include "Shape3.h"
#include <math.h>              //Pi constant
#include <string>
#include <iostream>

using namespace std;


/**************************************************************

   FUNCTION:   Cube(const double&);

   ARGUMENTS:  the length of one side

   RETURNS:    nothing

   NOTES:      Basic Constructer Inherited from Square
****************************************************************/

Cube::Cube(const double& r) : Square(r) {}

/**************************************************************

   FUNCTION:   Cube denstructer

****************************************************************/


Cube::~Cube(){}
/****************************************************************

   Function:   area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area 
****************************************************************/

double Cube::area() const
   {      //calculate area
    return (6 * Square::area());                        // returns area
   }
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the dimesnions
****************************************************************/

void Cube::print() const
   {
       Square::print(); 
   }

/**************************************************************

   FUNCTION:   Find volume of Cube

****************************************************************/


double Cube:: volume() const
{
   return (length * Square::area());
}


/**************************************************************

   FUNCTION:   Box(const double&, const double&, const double&);

   ARGUMENTS:  dimensions

   RETURNS:    nothing

   NOTES:      Basic Constructer inherits from rectangle
****************************************************************/

Box::Box(const double& l, const double& w, const double& h) : Rectangle(l,w)
   {
    height = h;
   }


Box::~Box(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Box::area() const
   {      //calculate area
    return ( (2 * Rectangle::area()) + (height* Rectangle::perimeter()) ) ;                        // returns area
   }
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void Box::print() const
   {
       Rectangle::print(); cout << " : height = " << height; 
   }

double Box::volume() const
{
   return (height * Rectangle::area());
}

/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/

Cylinder::Cylinder(const double& r, const double& h) : Circle(r)
   {
      height = h;
   }


Cylinder::~Cylinder(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Cylinder::area() const
{
   return ( (2 * Circle::area()) + (height * Circle::perimeter()) );      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void Cylinder::print() const
{
    Circle::print(); cout << " : height = " << height; 
}


double Cylinder::volume() const
{
   return (height * Circle::area());
}


/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/
Cone::Cone() : Circle(0) { height = 0;};

Cone& Cone::operator=(const Cone& c)
{
   if (this != &c)
   {
      radius = c.radius;
      height = c.height;
   }
   return *this;
}

Cone& Cone::operator+=(const Cone& c)
{
   radius += c.radius;
   height += c.height;
   return *this;
}


Cone::Cone(const double& r, const double& h) : Circle(r)
   {
      height = h;
   }


Cone::~Cone(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Cone::area() const
{
   return (Circle::area() + (1/2.0) * sqrt( (height * height) + (radius * radius) ) * Circle::perimeter());      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void Cone::print() const
{ 
   Circle::print(); cout << " : height = " << height;
}

double Cone:: volume() const
{
   return Circle::area() * height * (1/3.0);
}

/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/

Sphere::Sphere(const double& r) : Circle(r){}


Sphere::~Sphere(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Sphere::area() const
{
   return Circle::area() * 4;      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/


double Sphere::volume() const
{
   return (4/3.0) * radius * Circle::area();
}

/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/


Tetrahedron::Tetrahedron(const double& s) : equTriangle(s){}

Tetrahedron::~Tetrahedron(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Tetrahedron::area() const
{
   return (4 * (1/2.0) * a * ((a/2.0) * sqrt(3)) ) ;
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

double Tetrahedron::volume() const
{
   return ( (area()/4.0) * (1/3.0) * sqrt(2/3.0) * a );
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& t)
{
   if (this != &t)
   {
      a = t.a;
      b = t.b;
      c = t.c;
   }
   return *this;
}

Tetrahedron& Tetrahedron::operator+=(const Tetrahedron& t)
{
   a += t.a;
   b += t.b;
   c += t.c;

   return *this;
}

Tetrahedron::Tetrahedron(const Tetrahedron& t) : equTriangle(t)
{
   *this = t;
} 

Tetrahedron::Tetrahedron() : equTriangle(0){};





