#pragma once
#include <math.h>
#include <cmath>
using namespace std;

class Shape
{
protected:
    double areaRect;
    double areaCirc;

public:
    virtual double area() = 0;
    virtual bool isLargerThan(Shape *s1) = 0;
    virtual string printType() = 0;

    double getAreaRect()
    {
        return areaRect;
    }
    double getAreaCirc()
    {
        return areaCirc;
    }

    int cornerRect()
    {
        return 4;
    }

    int cornerCirc()
    {
        return 0;
    }

    // Virtual destructor
    virtual ~Shape()
    {
    }
};

class Point2D : public Shape
{
    // protected:
    int a;
    int b;

public:
    // Constructor
    Point2D(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    // Default Constructor
    Point2D()
    {
        a = 0;
        b = 0;
    }

    // Destructor
    ~Point2D()
    {
        // cout << "\nDestructor OK!" << endl;
    }

    // Distance
    double distance(Point2D ujpont)
    {
        return sqrt(((b - a) ^ 2) + ((ujpont.b - ujpont.a) ^ 2));
    }

    // Area
    double area()
    {
        return 0.0;
    };

    // Getters
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    // Type
    string printType()
    {
        return "Point2D";
    }

    // IsLarger
    bool isLargerThan(Shape *s1)
    {
        return false;
    }
};

class Rectangle : public Point2D
{
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

public:
    // Constructor
    Rectangle(Point2D a, Point2D b, Point2D c, Point2D d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    // Destructor
    ~Rectangle()
    {
        // cout << "\nDestructor OK!" << endl;
    }

    // Disable copy Constructor
    Rectangle &operator=(const Rectangle &) = delete;
    Rectangle(const Rectangle &) = delete;
    Rectangle() = delete;

    // Area
    double area()
    {
        int id1 = a.getA();
        int id2 = d.getA();
        int egyikoldalhossz = id2 - id1;
        id1 = a.getB();
        id2 = b.getB();
        int masikoldalhossz = id2 - id1;
        areaRect = abs(egyikoldalhossz * masikoldalhossz);
        return abs(areaRect);
    }

    // Type
    string printType()
    {
        return "Rectangle";
    }

    // IsLarger than circle
    bool isLargerThan(Shape *s1)
    {
        if (s1->area() > s1->getAreaCirc())
            return true;
        else
            return false;
    }
};

class Circle : public Point2D
{
    // protected:
    Point2D a;
    int b;

public:
    // Constructor
    Circle(Point2D a, int b)
    {
        this->a = a;
        this->b = b;
    }

    // Destructor
    ~Circle()
    {
        // cout << "\nDestructor OK!" << endl;
    }

    // Disable copy Constructor
    Circle &operator=(const Circle &) = delete;
    Circle(const Circle &) = delete;
    Circle() = delete;

    // Area
    double area()
    {
        areaCirc = M_PI * pow(b, 2);
        return areaCirc;
    }

    // Type
    string printType()
    {
        return "Circle";
    }

    // IsLarger than rectangle
    bool isLargerThan(Shape *s1)
    {
        if (s1->area() > s1->getAreaRect())
            return true;
        else
            return false;
    }
};

// Corners
int getSarkokSzama(Shape *s1)
{
    if (s1->getAreaCirc())
        return s1->cornerCirc();
    if (s1->getAreaRect())
        return s1->cornerRect();
}
