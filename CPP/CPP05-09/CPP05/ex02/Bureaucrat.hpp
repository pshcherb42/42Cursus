#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include "AForm.hpp"
#include <exception>
#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		int getGrade() const;
		const std::string getName() const;

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Grade is too low!";
				}
		};

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Grade is too high!";
				}
		};

		void incrementGrade(int increment);
		void decrementGrade(int decrement);

		void signForm(AForm& f);

		void executeForm(AForm const & form) const;

		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif