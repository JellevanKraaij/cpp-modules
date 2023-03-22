#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    void execute(const Bureaucrat& bureaucrat) const;
    static AForm* create(const std::string& name);
};
