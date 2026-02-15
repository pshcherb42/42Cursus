#include "ShrubberyCreationForm.hpp"


// call AForm constructor with specific grades
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other); // call base class assignment operator
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	AForm::performChecks(executor);

	std::ofstream outfile ((_target + "_shrubbery").c_str()) ;
	if (!outfile.is_open()) 
		throw std::runtime_error("Could not open outfile!");
	
	outfile << "       *" << std::endl;
    outfile << "      /|\\" << std::endl;
    outfile << "     /*|O\\" << std::endl;
    outfile << "    /*/|\\*\\" << std::endl;
    outfile << "   /X/O|*\\X\\" << std::endl;
    outfile << "  /*/X/|\\X\\*\\" << std::endl;
    outfile << " /O/*/X|*\\O\\X\\" << std::endl;
    outfile << "/*/O/X/|\\X\\O\\*\\" << std::endl;
    outfile << "        |" << std::endl;
    outfile << "        |" << std::endl;

	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}