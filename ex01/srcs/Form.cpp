#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, bool isSign, const int gradeSign, const int gradeExec)
    : _name(name),
    _isSigned(isSign),
    _gradeToSign(gradeSign),
    _gradeToExecute(gradeExec)
{
    if (_gradeToSign < MAXGRADE || _gradeToExecute < MAXGRADE)
        throw Form::GradeTooHighException();
    if (_gradeToSign > MINGRADE || _gradeToExecute > MINGRADE)
        throw Form::GradeTooLowException();
    return ;
}

Form::Form(const Form& other)
    : _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
    if (_gradeToSign < MAXGRADE || _gradeToExecute < MAXGRADE)
        throw Form::GradeTooHighException();
    if (_gradeToSign > MINGRADE || _gradeToExecute > MINGRADE)
        throw Form::GradeTooLowException();
    return ;
}

Form::~Form(void)
{
    return ;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

std::string Form::getName(void) const
{
    std::string ret_name = this->_name;
    return (ret_name);
}

bool Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

int Form::getGradeToSign(void) const
{
    int ret_grade_sign = this->_gradeToSign;
    return (ret_grade_sign);
}

int Form::getGradeToExec(void) const
{
    int ret_grade_exec = this->_gradeToExecute;
    return (ret_grade_exec);
}

void Form::beSigned(const Bureaucrat& person)
{
    if (person.getGrade() <= this->_gradeToSign)
    {
        std::cout << person.getName() << " signed " << this->_name << std::endl;
        this->_isSigned = true;
    }
    else
    {
        std::cout << person.getName() << " couldnt sign " << this->_name << " because: ";
        throw Form::GradeTooLowException();
    }
    return ;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    std::cout << "Exception caught" << std::endl;
    return ("The grade for form signing/executing is too high.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    std::cout << "Exception caught" << std::endl;
    return ("The grade for form signing/executing is too low.");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << " form is ";
    if (form.getIsSigned())
        out << "signed." << std::endl;
    else
        out << "not signed." << std::endl;
    out << "Bureaucrat needs to have higher (or same) grade than " << form.getGradeToSign() << " to sign it." << std::endl;
    out << "Bureaucrat needs to have higher (or same) grade than " << form.getGradeToExec() << " to execute it." << std::endl;
    return (out);
}