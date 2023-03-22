#pragma once

#include <ostream>
#include <string>

class AForm;

#include "Bureaucrat.hpp"

class AForm {
   public:
    AForm();
    AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
    AForm(const AForm& other);
    virtual ~AForm();

    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

    class Exception;
    class GradeTooHighException;
    class GradeTooLowException;
    class notSignedException;

   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

class AForm::Exception : public std::exception {
   public:
    Exception(const char* what);
    const char* what() const _NOEXCEPT;

   private:
    const char* _what;
};

class AForm::GradeTooHighException : public AForm::Exception {
   public:
    GradeTooHighException();
};

class AForm::GradeTooLowException : public AForm::Exception {
   public:
    GradeTooLowException();
};

class AForm::notSignedException : public AForm::Exception {
   public:
    notSignedException();
};
