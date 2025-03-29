#pragma once

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        virtual void execute(Bureaucrat const& executor) const;
};