#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat bob("Bob", 20);
    
    // Create forms
    AForm* form = intern.makeForm("shrubbery", "home");
    AForm* request = intern.makeForm("ROBOTOMY", "Polina");
    AForm* pardon = intern.makeForm("presidential pardon", "Arnau");
    AForm* invalid = intern.makeForm("invalid form", "test");
    
    std::cout << "\n=== Testing with safe pointer functions ===" << std::endl;
    
    // Use the NEW pointer-based functions (safe with NULL)
    bob.signForm(form);     // Works if form exists
    bob.executeForm(form);  // Works if form exists
    
    bob.signForm(request);     // Works if request exists
    bob.executeForm(request);  // Works if request exists
    
    bob.signForm(pardon);     // Works if pardon exists
    bob.executeForm(pardon);  // Works if pardon exists
    
    bob.signForm(invalid);     // Safe with NULL - prints error message
    bob.executeForm(invalid);  // Safe with NULL - prints error message
    
    // Clean up (safe to delete NULL pointers)
    delete form;
    delete request;
    delete pardon;
    delete invalid;  // This is safe even if invalid is NULL
    
    return 0;
}