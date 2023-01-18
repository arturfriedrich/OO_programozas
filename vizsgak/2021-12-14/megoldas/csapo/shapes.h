#pragma once
#include <string>
#include <math.h>

class Shape {
public:
	virtual ~Shape() {}
	virtual double area() = 0;
	virtual std::string printType() = 0;
	bool isLargerThan(Shape* other) {
		return area() > other->area();
	}
};

class Point2D {
	double x;
	double y;
public:
	Point2D(double x, double y) : x(x), y(y) {}
	double distance(Point2D& other) {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	}
};

class Rectangle : public Shape {
	Point2D topLeft;
	Point2D bottomLeft;
	Point2D bottomRight;
	Point2D topRight;
public:
	Rectangle(Point2D tl, Point2D bl, Point2D br, Point2D tr) :
		topLeft(tl), bottomLeft(bl), bottomRight(br), topRight(tr)
	{}
	Rectangle(const Rectangle&) = delete;
	Rectangle& operator=(const Rectangle&) = delete;
	std::string printType() {
		return "Teglalap";
	}
	double area() override {
		return topLeft.distance(topRight) * topLeft.distance(bottomLeft);
	}
};

class Circle : public Shape {
	Point2D center;
	double radius;
public:
	Circle(Point2D c, double r) :
		center(c), radius(r)
	{}
	Circle(const Circle&) = delete;
	Circle& operator=(const Circle&) = delete;
	std::string printType() {
		return "Kor";
	}
	double area() override {
		return pow(radius,2) * 3.14;
	}
};

int getSarkokSzama(Shape* s) {
	if (Circle* c = dynamic_cast<Circle*>(s)) {
		return 0;
	}
	if (Rectangle* c = dynamic_cast<Rectangle*>(s)) {
		return 4;
	}
}