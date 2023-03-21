#pragma once

#include <ostream>
#include <string>

class Form;

#include "Bureaucrat.hpp"

class Form {
   public:
    Form();
    Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
    Form(const Form& other);
    ~Form();

    Form& operator=(const Form& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException;
    class GradeTooLowException;

   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

class Form::GradeTooHighException : public std::out_of_range {
   public:
    GradeTooHighException();
};

class Form::GradeTooLowException : public std::out_of_range {
   public:
    GradeTooLowException();
};
