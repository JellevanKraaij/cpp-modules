#include "Bureaucrat.hpp"

#include <ostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < highestGrade)
        throw GradeTooHighException();
    if (grade > lowestGrade)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (&rhs == this)
        return (*this);
    _grade = getGrade();
    return (*this);
}

const std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    if (_grade <= highestGrade)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= lowestGrade)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : out_of_range("Bureaucrat GradeTooHigh") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : out_of_range("Bureacrat GradeTooLow") {}
