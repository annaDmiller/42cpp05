#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(target, 145, 137)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        this->setIsSigned(other.getIsSigned());
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSigned() == false)
    {
        throw AForm::ExecuteNotSignedException();
        return ;
    }
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw AForm::GradeTooLowException();
        return ;
    }
    std::string filename = this->getName() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Failed to execute Shrubbery Creation Form because :";
        std::perror(filename.c_str());
        return ;
    }
    std::cout << executor.getName() << " executed Shrubbery Creation Form '" << this->getName() << "'." << std::endl;
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\ " << std::endl;
    file << " /~~         ~~\\ " << std::endl;
    file << "{               } " << std::endl;
    file << " \\  _-     -_  / " << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_ " << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
    return ;
}