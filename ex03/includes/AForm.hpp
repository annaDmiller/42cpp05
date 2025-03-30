#pragma once

# include <iostream>
# include <string>
# include <exception>

# define MAXGRADE 1
# define MINGRADE 150

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm(const std::string name, const int gradeSign, const int gradeExec);
        AForm(const AForm& other);
        virtual ~AForm(void);
        AForm& operator=(const AForm& other);

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void setIsSigned(bool value);

        void beSigned(const Bureaucrat& person);
        virtual void execute(Bureaucrat const& executor) const = 0;

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

        class ExecuteNotSignedException : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream& out, const AForm& person);