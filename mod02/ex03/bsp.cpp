#include "Point.hpp"

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3) {
    return (Fixed::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());

    /* Calculate area of triangle PBC */
    Fixed A1 = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());

    /* Calculate area of triangle PAC */
    Fixed A2 = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());

    /* Calculate area of triangle PAB */
    Fixed A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());

	if (A == 0)
		return (point == a);
	return (A == A1 + A2 + A3);
}
