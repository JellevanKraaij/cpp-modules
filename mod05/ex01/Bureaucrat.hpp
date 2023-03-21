#pragma once

#include <string>

class Bureaucrat;

#include "Form.hpp"

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& rhs);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form) const;

    static bool isGradeTooHigh(int grade);
    static bool isGradeTooLow(int grade);

    static const int highestGrade = 1;
    static const int lowestGrade = 150;

    class GradeTooHighException;
    class GradeTooLowException;

   private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

class Bureaucrat::GradeTooHighException : public std::out_of_range {
   public:
    GradeTooHighException();
};

class Bureaucrat::GradeTooLowException : public std::out_of_range {
   public:
    GradeTooLowException();
};
