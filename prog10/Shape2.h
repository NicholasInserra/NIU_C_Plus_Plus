
/****************************************************************
   FILE:      Shape2.h
   AUTHOR:    Nick Inserra
   LOGON ID:  Z1749082
   DUE DATE:  4/20/2016

   PURPOSE:   Protypes for Circle Rectange Triangle
              Uses Shape as a base class
              Subclass of Triangle: equTriangle rightTriangle
              Subclass of Rectangle: Square
****************************************************************/

#ifndef SHAPE2_H
#define SHAPE2_H

#include "Shape.h" //abstract base class
#include <string>

using namespace std;

class Circle : public Shape
{
   public:
      Circle();
      Circle(const double&);    //constructer
      Circle(const Circle&);            //copy constructer
      ~Circle();

      double perimeter() const;
      double area() const;
      void print() const;

      Circle& operator=(const Circle&);
      Circle& operator+=(const Circle&);

   protected:
      double radius;
};

class Rectangle : public Shape
{
   public:
      Rectangle();
      Rectangle(const double&, const double&);    //constructer
      Rectangle(const Rectangle&);            //copy constructer
      ~Rectangle();

      double perimeter() const;
      double area() const;
      void print() const;

      Rectangle& operator=(const Rectangle&);
      Rectangle& operator+=(const Rectangle&);

   protected:
      double width;
      double length;
};

class Triangle : public Shape
{
   public:
      Triangle() : a(0), b(0), c(0) {};
      Triangle(const double&, const double&, const double&);    //constructer
      Triangle(const Triangle&);            //copy constructer
      ~Triangle();

      double perimeter() const;
      double area() const;
      void print() const;

      Triangle& operator=(const Triangle&);
      Triangle& operator+=(const Triangle&);

   protected:
      double a, b, c;
};

class rightTriangle : public Triangle
{
   public:
      rightTriangle(const double&, const double&);    //constructer
      rightTriangle(const rightTriangle&);            //copy constructer
      ~rightTriangle();

      double perimeter() const;
      double area() const;
      void print() const;

      rightTriangle& operator=(const rightTriangle&);
      rightTriangle& operator+=(const rightTriangle&);
};

class equTriangle : public Triangle
{
   public:
      equTriangle();
      equTriangle(const double&);    //constructer
      equTriangle(const equTriangle&);            //copy constructer
      ~equTriangle();

      double perimeter() const;
      double area() const;
      void print() const;

      equTriangle& operator=(const equTriangle&);
      equTriangle& operator+=(const equTriangle&);
};

class Square : public Rectangle
{
   public:
      Square();
      Square(const double&);    //constructer
      Square(const Square&);            //copy constructer
      ~Square();

      double perimeter() const;
      double area() const;
      void print() const;

      Square& operator=(const Square&);
      Square& operator+=(const Square&);
};

#endif
