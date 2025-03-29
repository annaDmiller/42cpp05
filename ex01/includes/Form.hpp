#pragma once

# include <iostream>
# include <string>
# include <exception>

# define MAXGRADE 1
# define MINGRADE 150

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form(const std::string name, bool isSign, const int gradeSign, const int gradeExec);
        Form(const Form& other);
        ~Form(void);
        Form& operator=(const Form& other);

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void beSigned(const Bureaucrat& person);

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

std::ostream &operator<<(std::ostream& out, const Form& person);