#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
{
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        this->setIsSigned(other.getIsSigned());
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
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
    std::cout << executor.getName() << " executed Presidential Pardon Form '" << this->getName() << "'." << std::endl;
    std::cout << this->getName() << " is pardoned by the president Zaphod Beeblebrox." << std::endl;
    return ;
}