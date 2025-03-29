#pragma once

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        virtual void execute(Bureaucrat const& executor) const;
};