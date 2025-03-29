#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name),
    _grades(grade)
{
    if (_grades < MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (_grades > MINGRADE)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat with " << _name << " name and " << _grades << " grade is created" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name),
    _grades(other._grades)
{
    if (_grades < MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (_grades > MINGRADE)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat with " << _name << " name and " << _grades << " grade is created" << std::endl;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grades = other._grades;
    if (_grades < MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (_grades > MINGRADE)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat with " << _name << " name and " << _grades << " grade is copied" << std::endl;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    std::string ret;
    ret = this->_name;
    return (ret);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grades);
}

void Bureaucrat::increaseGrade(void)
{
    if (_grades - 1< MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
    --(this->_grades);
    return ;
}

void Bureaucrat::decreaseGrade(void)
{
    if (_grades + 1> MINGRADE)
        throw Bureaucrat::GradeTooLowException();
    ++(this->_grades);
    return ;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    std::cout << "Exception caught" << std::endl;
    return ("The grade of bureaucrat can't be higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    std::cout << "Exception caught" << std::endl;
    return ("The grade of bureaucrat can't be lower than 150");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& person)
{
    out << person.getName();
    out << ", bureaucrat grade ";
    out << person.getGrade();
    out << "." << std::endl;
    return (out);
}

void Bureaucrat::signForm(Form& form) const
{
    if (form.getIsSigned())
        return ;
    form.beSigned(*this);
    return ;
}