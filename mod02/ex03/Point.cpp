#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const int x, const int y) : _x(x), _y(y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
}

Point::~Point() {}

Point &Point::operator=(const Point &other) {
	(void)other;
	return(*this);
}

std::ostream& operator<<(std::ostream &os, const Point &cl) {
	os << cl.getX() << "," << cl.getY();
	return(os);
}

bool Point::operator==(const Point &rhs) const {
	return (this->getX() == rhs.getX() && this->getY() == rhs.getY());
}


const Fixed &Point::getX() const {
	return (_x);
}
const Fixed &Point::getY() const {
	return (_y);
}
