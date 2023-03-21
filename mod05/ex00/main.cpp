#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    std::cout << "create bureaucrat with a grade that is too high" << std::endl;
    try {
        Bureaucrat test1("test", 0);
    } catch (const std::exception &e) {
        std::cout << "caught exception, message: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "create bureaucrat with a grade that is too low" << std::endl;
    try {
        Bureaucrat test1("test", 151);
    } catch (const std::exception &e) {
        std::cout << "caught exception, message: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "create 2 bureaucrats with grades of 1 and 150" << std::endl;

    Bureaucrat test1("test1", 1);
    Bureaucrat test2("test2", 150);

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
    std::cout << std::endl;

    std::cout << "decrement test1 grade & increment test2 grade" << std::endl;

    test1.decrementGrade();
    test2.incrementGrade();

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
    std::cout << std::endl;

    std::cout << "increment test1 grade & decrement test2 grade" << std::endl;

    test1.incrementGrade();
    test2.decrementGrade();

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
    std::cout << std::endl;

    std::cout << "increment test1 grade above highest grade" << std::endl;
    try {
        test1.incrementGrade();
    } catch (const std::exception &e) {
        std::cout << "caught exception, message: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "decrement test2 grade below lowest grade" << std::endl;
    try {
        test2.decrementGrade();
    } catch (const std::exception &e) {
        std::cout << "caught exception, message: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "values should be unchanged" << std::endl;

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
}
