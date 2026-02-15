#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _sign;
		const int _gradeSign;
		const int _gradeExec;
	public:
		AForm();
		AForm(const std::string& name, const int gradeSign, const int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return ("Grade is too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return ("Grade is too low!");
				}
		};

		class InvalidGradeException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Invalid parameters";
				}
		};

		class FormIsNotSignedException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Form is not signed";
				}
		};

		const std::string getName() const;
		bool getSign();
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& m);

		virtual void execute(Bureaucrat const & executor) const = 0;
		void performChecks(Bureaucrat const & executor) const;

		virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif