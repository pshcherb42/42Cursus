#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <string>
#include <fstream>
#include <ostream>

class ShrubberyCreationForm : public AForm {
	private :
		std::string _target; // target name not another form
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		virtual void execute(Bureaucrat const & executor) const;

		~ShrubberyCreationForm();
};

#endif