#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _sign;
		const int _gradeSign;
		const int _gradeExec;
	public:
		Form();
		Form(const std::string& name, const int gradeSign, const int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);

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

		const std::string getName() const;
		bool getSign();
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& m);

		~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif