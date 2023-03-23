#include "RobotomyRequestForm.hpp"

#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
    AForm::execute(bureaucrat);
    std::cout << "Dri..lllin...nggg..." << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2) {
        std::cout << getName() << " robotomizing failed" << std::endl;
        return;
    }
    std::cout << getName() << " has been robotomized" << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string& name) {
    return new RobotomyRequestForm(name);
}