#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    void execute(const Bureaucrat& bureaucrat) const;
    static AForm* create(const std::string& name);
};
