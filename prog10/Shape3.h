
/****************************************************************
   FILE:      Shape3.h
   AUTHOR:    Nick Inserra
   LOGON ID:  Z1749082
   DUE DATE:  4/20/2016

   PURPOSE:   Protypes for 3d shapes
              Shape is still ultimate base class
              But no 3d shapes are directly derived from it
****************************************************************/

#ifndef SHAPE3_H
#define SHAPE3_H


#include "Shape2.h"
#include <string>
#include <iostream>
using namespace std;

class Cube : public Square
{
   public:
      Cube(const double&);    //constructer
      Cube(const Cube&);            //copy constructer
      ~Cube();

      double perimeter() const { return 0;}
      double area() const;
      void print() const;
      double volume() const;
};

class Box : public Rectangle
{
   public:
      Box(const double&, const double&, const double&);    //constructer
      Box(const Box&);            //copy constructer
      ~Box();

      double perimeter() const {return 0;}
      double area() const;
      double volume() const;
      void print() const;

  private:
      double height;
};

class Cone : public Circle
{
   public:
      Cone();
      Cone(const double&, const double&);    //constructer
      Cone(const Cone&);            //copy constructer
      ~Cone();

      double perimeter() const {return 0;};
      double area() const;
      void print() const;
      double volume() const;

      Cone& operator=(const Cone&);
      Cone& operator+=(const Cone&);
  private:
      double height;
};


class Cylinder : public Circle
{
   public:
      Cylinder(const double&, const double&);    //constructer
      Cylinder(const Cylinder&);            //copy constructer
      ~Cylinder();

      double perimeter() const {return 0;};
      double area() const;
      void print() const;
      double volume() const;
      Cylinder& operator=(const Cylinder&);
      Cylinder& operator+=(const Cylinder&);

  private:
      double height;

};

class Sphere : public Circle
{
   public:
      Sphere(const double&);    //constructer
      Sphere(const Sphere&);            //copy constructer
      ~Sphere();


      double area() const;
      double volume() const;

      Sphere& operator=(const Sphere&);
      Sphere& operator+=(const Sphere&);
};

class Tetrahedron : public equTriangle
{
   public:
      Tetrahedron();
      Tetrahedron(const double&);    //constructer
      Tetrahedron(const Tetrahedron&);            //copy constructer
      ~Tetrahedron();

      double perimeter() const {return 0;};
      double area() const;
      double volume() const;

      Tetrahedron& operator=(const Tetrahedron&);
      Tetrahedron& operator+=(const Tetrahedron&);
};

#endif
