#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        this->setIsSigned(other.getIsSigned());
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSigned() == false)
    {
        throw AForm::ExecuteNotSignedException();
        return ;
    }
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw AForm::GradeTooLowException();
        return ;
    }
    srand(time(NULL));
    if (rand() % 2 == 1)
    {
        std::cout << "The robotomy of '" << this->getName() << "' is failed." << std::endl;
        return ;
    }
    std::cout << executor.getName() << " executed Robotomy Request Form '" << this->getName() << "'." << std::endl;
    std::cout << this->getName() << " has been robotomized successfully." << std::endl;
    return ;
}