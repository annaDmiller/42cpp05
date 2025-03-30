#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::Intern(const Intern& other)
{
    (void) other;
    return ;
}

Intern::~Intern(void)
{
    return ;
}

Intern& Intern::operator=(const Intern& other)
{
    (void) other;
    return (*this);
}

AForm* Intern::makeForm(std::string type, std::string target) const
{
    std::string types[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    forms forms_arr[] = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

    transform(type.begin(), type.end(), type.begin(), ::tolower);

    for (int ind = 0; ind < 3; ind++)
    {
        if (type == types[ind])
        {
            std::cout << "Intern creates " << type << std::endl;
            AForm* ret = (this->*forms_arr[ind])(target);
            return (ret);
        }
    }
    std::cerr << "Intern can't create " << type << " form. There is no such form." << std::endl;
    return (NULL);
}

AForm* Intern::createPresidentialPardonForm(std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}