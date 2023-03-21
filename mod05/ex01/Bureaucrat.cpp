#include "Bureaucrat.hpp"

#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (isGradeTooHigh(grade))
        throw GradeTooHighException();
    if (isGradeTooLow(grade))
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (&other == this)
        return (*this);
    _grade = other._grade;
    return (*this);
}

const std::string& Bureaucrat::getName() const {
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

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "(" << *this << ") could't sign (" << form << ") because (" << e.what() << ")" << std::endl;
        return;
    }
    std::cout << "(" << *this << ") signed (" << form << ")" << std::endl;
}

bool Bureaucrat::isGradeTooHigh(int grade) {
    return (grade < highestGrade);
}

bool Bureaucrat::isGradeTooLow(int grade) {
    return (grade > lowestGrade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << ", with grade " << bureaucrat.getGrade();
    return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : out_of_range("Bureaucrat GradeTooHigh") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : out_of_range("Bureaucrat GradeTooLow") {}
