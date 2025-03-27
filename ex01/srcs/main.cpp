#include "Bureaucrat.hpp"

int main(void)
{
    {
        Bureaucrat first("first", 30);
        std::cout << first;
    }
    std::cout << std::endl;
    {
        std::cout << "Attempting to create bureaucrat with grade 0" << std::endl;    
        try
        {
            Bureaucrat second("second", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << std::endl;
    {
        std::cout << "Attempting to create bureaucrat with grade 151" << std::endl;    
        try
        {
            Bureaucrat third("third", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << std::endl;
    {
        Bureaucrat forth("forth", 1);
        std::cout << forth;
        std::cout << "Attempting to increase the grade of forth" << std::endl;    
        try
        {
            forth.increaseGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << std::endl;
    {
        Bureaucrat fifth("fifth", 150);
        std::cout << fifth;
        std::cout << "Attempting to decrease the grade of fifth" << std::endl;    
        try
        {
            Bureaucrat second("second", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    return (0);
}