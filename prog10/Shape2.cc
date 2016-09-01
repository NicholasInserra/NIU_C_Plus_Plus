
/***********************************************************
CSCI 689 Assignment 10

Progammer: Nick Inserra
Section: 1
Date Due: 4/20  

File Name:  Shape2.cc

Purpose:  Holds the class implemntation for a series of 2d shapes
          including Circle, Triangle, Rectangle, Right Triangle and more
          All clases are derived from shape some are derived from other classe          that derive from shape
************************************************************/
#include "Shape2.h"
#include <math.h>              //Pi constant
#include <string>
#include <iostream>



using namespace std;


/**************************************************************

   FUNCTION:   Circle(const double&);

   ARGUMENTS:  double radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/

Circle::Circle(const double& r)
{
    radius = r;
}

/**************************************************************

   FUNCTION:   ~Circle();

   ARGUMENTS:  none

   RETURNS:    nothing

   NOTES:      Destructer
****************************************************************/


Circle::~Circle(){}



/**************************************************************

   FUNCTION:   += operator

   ARGUMENTS:  const Circle&

   RETURNS:    Circle&

   NOTES:      += overload
****************************************************************/


Circle& Circle::operator+=(const Circle& c)
{
   radius += c.radius;
   return *this;
}



/****************************************************************

   Function:   area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Circle::area() const
   {
    double area;
    area = (M_PI * (radius * radius));      //calculate area
    return area;                        // returns area
   }
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints radius
****************************************************************/

void Circle::print() const  { cout << "radius = " << radius; }

double Circle:: perimeter() const
{
   return (2 * M_PI * radius);
}


/**************************************************************

   FUNCTION:   Rectangle(const double&, const double&);

   ARGUMENTS:  height and length

   RETURNS:    nothing

   NOTES:      Constructers
****************************************************************/

Rectangle::Rectangle()
{
   length = 0;
   width = 0;
}

Rectangle::Rectangle(const double& l, const double& w )
   {
    length = l;
    width = w;
   }

/**************************************************************

   FUNCTION:   +=(const Rectangle&);

****************************************************************/


Rectangle& Rectangle::operator=(const Rectangle& c)
{
   if (this != &c)
   {
      length = c.length;
      width = c.width;
   }
   return *this;
}


/**************************************************************

   FUNCTION:   ~Rectangle() destrcuter

****************************************************************/

Rectangle::~Rectangle(){}

/****************************************************************

   Function:   area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area w * l
****************************************************************/

double Rectangle::area() const
   {
    double area;
    area = (length * width);      //calculate area
    return area;                        // returns area
   }
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the dimesnions
****************************************************************/

void Rectangle::print() const
   { 
      cout << "length = " << length << " : width = " << width;
   }

double Rectangle:: perimeter() const
{
   return (2 * length) + (2 * width);
}

/**************************************************************

   FUNCTION:   Triangle constructer

****************************************************************/

Triangle::Triangle(const double& s1, const double& s2, const double& s3)
   {
      a = s1; b = s2; c = s3;
   }

/**************************************************************

   FUNCTION:   Triangle Copy constructer

****************************************************************/


Triangle::Triangle(const Triangle& t)
{
   a = t.a;
   b = t.b;
   c = t.c;
}

Triangle::~Triangle() {}

/****************************************************************

   Function:   area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area
****************************************************************/

double Triangle::area() const
{
   double k = (perimeter()/2.0);
   return sqrt(k * (k-a) * (k-b) * (k-c));      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the dimesnions
****************************************************************/

void Triangle::print() const
   { 
      cout << "a = " << a << " : b = " << b << " : c = " << c;
   }

/**************************************************************

   FUNCTION:   Find Triangle perimeter

****************************************************************/


double Triangle::perimeter() const
{
   return (a + b + c);
}


/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/

rightTriangle::rightTriangle(const double& s1, const double& s2) : Triangle(s1, s2, 0)
   {
      c = sqrt ( (a*a) + (b*b) );
   }


rightTriangle::~rightTriangle()
{
}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double rightTriangle::area() const
{
   return Triangle::area();      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void rightTriangle::print() const
   { 
      cout << "length = " << a << " : height = " << b;
   }

double rightTriangle:: perimeter() const
{
   return Triangle::perimeter();
}

/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/
equTriangle::equTriangle() : Triangle() {};

equTriangle::equTriangle(const equTriangle& t) : Triangle(t) {}

equTriangle::equTriangle(const double& s1) : Triangle(s1, s1, s1){}


equTriangle::~equTriangle(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double equTriangle::area() const
{
   return Triangle::area();      
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void equTriangle::print() const
   { 
      cout << "length = " << a;
   }

double equTriangle:: perimeter() const
{
   return Triangle::perimeter();
}

/**************************************************************

   FUNCTION:   Circle(const string&, const int&);

   ARGUMENTS:  const string& of color, const int& of radius

   RETURNS:    nothing

   NOTES:      Basic Constructer
****************************************************************/


Square::Square(const double& s) : Rectangle(s, s){}

Square::Square() : Rectangle(){}

Square::~Square(){}
/****************************************************************

   Function:   get_area()

   Arguments:  none

   Returns:   double of the area

   Notes:  Calcualtes area of a cricle using pi * (R * R)
****************************************************************/

double Square::area() const
{
   return Rectangle::area();
}
/****************************************************************

   FUNCTION:   print()

   ARGUMENTS:  none

   RETURNS:    void

   NOTES:      prints the color, radius, area
****************************************************************/

void Square::print() const
{ 
      cout << "length = " << length;
}

double Square:: perimeter() const
{
   return Rectangle::perimeter();
}
