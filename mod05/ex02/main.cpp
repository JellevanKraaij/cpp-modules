#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    ShrubberyCreationForm trees("trees");

    Bureaucrat validBureaucrat("validBureaucrat", 137);
    Bureaucrat invalidBureaucrat("invalidBureaucrat", 138);

    validBureaucrat.executeForm(trees);

    validBureaucrat.signForm(trees);

    invalidBureaucrat.executeForm(trees);
    validBureaucrat.executeForm(trees);

    std::cout << std::endl;

    std::cout << "testing other forms" << std::endl;
    Bureaucrat sudoCrat("SudoCrat", 1);

    std::cout << std::endl;

    RobotomyRequestForm robot("robot");
    robot.beSigned(sudoCrat);
    robot.execute(sudoCrat);

    std::cout << std::endl;

    PresidentialPardonForm president("president");
    president.beSigned(sudoCrat);
    president.execute(sudoCrat);
}
