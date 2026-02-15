#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	//AForm m;
	// In main:
	ShrubberyCreationForm form("home");
	RobotomyRequestForm request("Polina");
	PresidentialPardonForm pardon("Arnau");
	Bureaucrat bob("Bob", 100);

	// This will fail because form is not signed
	bob.executeForm(form);  // Output: "Bob couldn't execute ShrubberyCreationForm because Form is not signed"

	// Sign the form first
	bob.signForm(form);

	// Now execution succeeds
	bob.executeForm(form);  // Output: "Bob executed ShrubberyCreationForm"

	// create bureaucrat able to execute the request
	Bureaucrat pop("Pop", 40);

	// sign the request
	pop.signForm(request);

	// execute request
	pop.executeForm(request);

	Bureaucrat dod("Dod", 3);

	dod.signForm(pardon);
	dod.executeForm(pardon);
}