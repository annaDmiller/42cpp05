#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    Bureaucrat person("Kevin", 1);
    {
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        person.signForm(*rrf);
        person.executeForm(*rrf);

        delete(rrf);
    }
    std::cout << std::endl;
    {
        AForm* ppf;

        ppf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
        person.signForm(*ppf);
        person.executeForm(*ppf);

        delete(ppf);
    }
    std::cout << std::endl;
    {
        AForm* scf;

        scf = someRandomIntern.makeForm("SHRUBBERY creation", "Bender");
        person.signForm(*scf);
        person.executeForm(*scf);

        delete(scf);
    }
    std::cout << std::endl;
    {
        AForm* other;

        other = someRandomIntern.makeForm("Presidential request", "Bender");
        if (other == NULL)
            std::cerr << "Nothing to be signed and executed." << std::endl;
    }
    return (0);
}