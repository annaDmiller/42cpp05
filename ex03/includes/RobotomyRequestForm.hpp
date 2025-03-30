#pragma once

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>
# include <stdlib.h>
# include <time.h>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        virtual void execute(Bureaucrat const& executor) const;
};