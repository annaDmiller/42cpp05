#pragma once

# include <iostream>
# include <string>

# define MAXGRADE 1
# define MINGRADE 150

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
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& person);