#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    {
        AForm *ppf = new PresidentialPardonForm("Test");
        Bureaucrat person("First", 20);
        try
        {
            person.signForm(*ppf);
            person.executeForm(*ppf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete ppf;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *ppf = new PresidentialPardonForm("Test");
        Bureaucrat person("First", 20);
        try
        {
            person.executeForm(*ppf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete ppf;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *ppf = new PresidentialPardonForm("Test");
        Bureaucrat person("First", 3);
        try
        {
            person.signForm(*ppf);
            person.executeForm(*ppf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete ppf;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *rrf = new RobotomyRequestForm("Test");
        Bureaucrat person("First", 30);
        try
        {
            person.signForm(*rrf);
            person.executeForm(*rrf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete rrf;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        AForm *scf = new ShrubberyCreationForm("Test");
        Bureaucrat person("First", 130);
        try
        {
            person.signForm(*scf);
            person.executeForm(*scf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete scf;
    }
    return (0);
}