#ifndef H_SHAPE
#define H_SHAPE

class Shape {
public:
    virtual double area ( ) const = 0;
    virtual double perimeter ( ) const = 0;
    virtual void print ( ) const = 0;

    virtual double volume ( ) const { return 0; }
    virtual ~Shape ( ) { }
};

#endif
