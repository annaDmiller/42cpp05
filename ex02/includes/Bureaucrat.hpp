#pragma once

# include <iostream>
# include <string>
# include <exception>

# define MAXGRADE 1
# define MINGRADE 150

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grades;

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int getGrade(void) const;
        void increaseGrade(void);
        void decreaseGrade(void);

        void signForm(AForm& form) const;
        void executeForm(AForm const& form) const;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& person);