#pragma once

#include "Fixed.hpp"
#include <ostream>

class Point {
   public:
	Point();
	Point(const int x, const int y);
	Point(const float x, const float y);
	Point(const Fixed &x, const Fixed &y);

	Point(const Point &other);

	~Point();

    bool operator==(const Point &rhs) const;

	const Fixed &getX() const;
	const Fixed &getY() const;

	Point &operator=(const Point &other);

   private:
	const Fixed _x;
	const Fixed _y;
};

std::ostream& operator<<(std::ostream &os, const Point &cl);
