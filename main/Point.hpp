#pragma once
#include <math.h>
#define nullptr 0
class Point {
private:
	double x;
	double y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double getX() const {
		return this->x;
	}
	double getY() const {
		return this->y;
	}
	double distanceFrom(Point* pPoint) {
		return sqrt(pow(this->x - pPoint->x,2)+pow(this->y - pPoint->y,2));
	}
};
