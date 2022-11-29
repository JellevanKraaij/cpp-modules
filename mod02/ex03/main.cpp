#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);

    std::cout << "triangle: " << a << ' ' << b << ' ' << c << std::endl;

    {
        Point test(0.5f, 0.5f);
        std::cout << "point: " << test << " is " << (bsp(a, b, c, test) ? "inside" : "outside") << std::endl;
    }
    {
        Point test(0.5f, -0.5f);
        std::cout << "point: " << test << " is " << (bsp(a, b, c, test) ? "inside" : "outside") << std::endl;
    }
}
