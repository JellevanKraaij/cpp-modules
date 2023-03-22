#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    void execute(const Bureaucrat& bureaucrat) const;
    static AForm* create(const std::string& name);
};
