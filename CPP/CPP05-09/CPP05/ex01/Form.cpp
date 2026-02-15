#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default name"), _sign(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	try {
		if (gradeSign > 150 || gradeExec > 150)
			throw Form::GradeTooLowException();
		if (gradeSign < 1 || gradeExec < 1)
			throw Form::GradeTooHighException();
	} catch(std::exception& e) {
		std::cout << "Caught out of range: " << e.what() << std::endl;
	}
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->~Form();
		new (this) Form(other);
	}
	return *this;
}

const std::string Form::getName() const { return _name; }
bool Form::getSign() { return _sign; }
int Form::getGradeSign() const { return _gradeSign; }
int Form::getGradeExec() const { return _gradeExec; }

void Form::beSigned(const Bureaucrat& m) {
	if (_gradeSign > 150 || m.getGrade() > 150 || m.getGrade() < 1 || _gradeSign < 1)
		throw Form::InvalidGradeException();
	if (m.getGrade() > _gradeSign) {
		throw Form::GradeTooLowException();
	}
	_sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	return os << obj.getName() << ", form grade required to sign " << obj.getGradeSign() << ", form grade required to execute " << obj.getGradeExec();
}

Form::~Form() {}