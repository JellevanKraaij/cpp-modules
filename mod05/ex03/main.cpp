#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;

    AForm *formP = intern.makeForm("presidential pardon", "presidential");
    AForm *formR = intern.makeForm("robotomy request", "robot");
    AForm *formS = intern.makeForm("shrubbery creation", "shrubbery");
    AForm *formI = intern.makeForm("nope", "nope");

    std::cout << *formP << std::endl;
    std::cout << *formR << std::endl;
    std::cout << *formS << std::endl;

    std::cout << formI << std::endl;

    delete formP;
    delete formR;
    delete formS;
    delete formI;
}
