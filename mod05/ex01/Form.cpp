#include "Form.hpp"

Form::Form()
    : _name("default"), _isSigned(false), _gradeRequiredToSign(Bureaucrat::highestGrade), _gradeRequiredToExecute(Bureaucrat::highestGrade) {}

Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (Bureaucrat::isGradeTooHigh(gradeRequiredToSign))
        throw GradeTooHighException();
    if (Bureaucrat::isGradeTooLow(gradeRequiredToSign))
        throw GradeTooLowException();
    if (Bureaucrat::isGradeTooHigh(gradeRequiredToExecute))
        throw GradeTooHighException();
    if (Bureaucrat::isGradeTooLow(gradeRequiredToExecute))
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    *this = other;
}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this == &other)
        return (*this);
    _isSigned = other._isSigned;
    return (*this);
}

const std::string& Form::getName() const {
    return (_name);
}

bool Form::getIsSigned() const {
    return (_isSigned);
}

int Form::getGradeRequiredToSign() const {
    return (_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const {
    return (_gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", with grade required to sign: " << form.getGradeRequiredToSign()
       << ", grade required to execute: " << form.getGradeRequiredToExecute() << ", is signed: " << std::boolalpha << form.getIsSigned();
    return (os);
}

Form::GradeTooHighException::GradeTooHighException() : out_of_range("Form GradeTooHigh") {}

Form::GradeTooLowException::GradeTooLowException() : out_of_range("Form GradeTooLow") {}
