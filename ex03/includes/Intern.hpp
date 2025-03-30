#pragma once

# include <iostream>
# include <string>
#include <bits/stdc++.h>

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class Intern;

typedef AForm* (Intern::*forms)(std::string&) const;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);
        Intern& operator=(const Intern& other);

        AForm* makeForm(std::string type, std::string target) const;

        AForm* createPresidentialPardonForm(std::string& target) const;
        AForm* createRobotomyRequestForm(std::string& target) const;
        AForm* createShrubberyCreationForm(std::string& target) const;
};