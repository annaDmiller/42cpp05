#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        try
        {
            Form test("Test", false, 0, 150);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
    std::cout << std::endl;
    {
        try
        {
            Form test("Test", false, 1, 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
    std::cout << std::endl;
    {
        Form test("Test", false, 4, 38);
        Bureaucrat person("Adam", 5);
        try
        {
            person.signForm(test);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
    std::cout << std::endl;
    {
        Form test("Test", false, 5, 38);
        Bureaucrat person("Adam", 5);
        try
        {
            person.signForm(test);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
    return (0);
}