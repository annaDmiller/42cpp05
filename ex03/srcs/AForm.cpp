#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec)
    : _name(name),
    _isSigned(false),
    _gradeToSign(gradeSign),
    _gradeToExecute(gradeExec)
{
    if (_gradeToSign < MAXGRADE || _gradeToExecute < MAXGRADE)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > MINGRADE || _gradeToExecute > MINGRADE)
        throw AForm::GradeTooLowException();
    return ;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
    if (_gradeToSign < MAXGRADE || _gradeToExecute < MAXGRADE)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > MINGRADE || _gradeToExecute > MINGRADE)
        throw AForm::GradeTooLowException();
    return ;
}

AForm::~AForm(void)
{
    return ;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

std::string AForm::getName(void) const
{
    std::string ret_name = this->_name;
    return (ret_name);
}

bool AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
    int ret_grade_sign = this->_gradeToSign;
    return (ret_grade_sign);
}

int AForm::getGradeToExec(void) const
{
    int ret_grade_exec = this->_gradeToExecute;
    return (ret_grade_exec);
}

void AForm::beSigned(const Bureaucrat& person)
{
    if (person.getGrade() <= this->_gradeToSign)
    {
        std::cout << person.getName() << " signed " << this->_name << std::endl;
        this->_isSigned = true;
    }
    else
    {
        std::cout << person.getName() << " couldnt sign " << this->_name << " because: ";
        throw AForm::GradeTooLowException();
    }
    return ;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
    std::cerr << "Exception caught" << std::endl;
    return ("The grade for form signing/executing is too high.");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    std::cerr << "Exception caught" << std::endl;
    return ("The grade for form signing/executing is too low.");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
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

void AForm::setIsSigned(bool value)
{
    this->_isSigned = value;
    return ;
}

const char* AForm::ExecuteNotSignedException::what(void) const throw()
{
    std::cerr << "Exception caught" << std::endl;
    return ("Attempting to execute the form while it's not signed yet.");
}
