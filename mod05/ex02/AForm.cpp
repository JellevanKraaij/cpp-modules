#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _gradeRequiredToSign(Bureaucrat::highestGrade), _gradeRequiredToExecute(Bureaucrat::highestGrade) {}

AForm::AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
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

AForm::AForm(const AForm& other)
    : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    *this = other;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this == &other)
        return (*this);
    _isSigned = other._isSigned;
    return (*this);
}

const std::string& AForm::getName() const {
    return (_name);
}

bool AForm::getIsSigned() const {
    return (_isSigned);
}

int AForm::getGradeRequiredToSign() const {
    return (_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const {
    return (_gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw notSignedException();

    if (executor.getGrade() > _gradeRequiredToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", with grade required to sign: " << form.getGradeRequiredToSign()
       << ", grade required to execute: " << form.getGradeRequiredToExecute() << ", is signed: " << std::boolalpha << form.getIsSigned();
    return (os);
}

AForm::Exception::Exception(const char* what) : _what(what) {}

const char* AForm::Exception::what() const _NOEXCEPT {
    return (_what);
}

AForm::GradeTooHighException::GradeTooHighException() : Exception("Form GradeTooHigh") {}

AForm::GradeTooLowException::GradeTooLowException() : Exception("Form GradeTooLow") {}

AForm::notSignedException::notSignedException() : Exception("Form notSigned") {}
