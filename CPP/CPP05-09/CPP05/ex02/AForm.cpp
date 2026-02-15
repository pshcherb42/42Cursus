#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default name"), _sign(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExec) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	try {
		if (gradeSign > 150 || gradeExec > 150)
			throw AForm::GradeTooLowException();
		if (gradeSign < 1 || gradeExec < 1)
			throw AForm::GradeTooHighException();
	} catch(std::exception& e) {
		std::cout << "Caught out of range: " << e.what() << std::endl;
	}
}

AForm::AForm(const AForm& other) : _name(other._name), _sign(other._sign), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		// cant use placement new with abstract class
		// only copy assignable members
		_sign = other._sign;
	}
	return *this;
}

const std::string AForm::getName() const { return _name; }
bool AForm::getSign() { return _sign; }
int AForm::getGradeSign() const { return _gradeSign; }
int AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(const Bureaucrat& m) {
	if (_gradeSign > 150 || m.getGrade() > 150 || m.getGrade() < 1 || _gradeSign < 1)
		throw AForm::InvalidGradeException();
	if (m.getGrade() > _gradeSign) {
		throw AForm::GradeTooLowException();
	}
	_sign = true;
}

void AForm::performChecks(Bureaucrat const & executor) const{
	//try {
		if (_sign == false)
			throw FormIsNotSignedException();
		if (_gradeSign > 150 || executor.getGrade() > 150 || executor.getGrade() < 1 || _gradeSign < 1
			|| _gradeExec > 150 || _gradeExec < 1)
			throw AForm::InvalidGradeException();
		if (executor.getGrade() > _gradeExec) {
			throw AForm::GradeTooLowException();
		}
		// if it gets here, all checks passed - no exception thrown
	/*} catch(std::exception& e) {
		std::cout << "Cannot execute the form because: " << e.what() << std::endl;
	}*/
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	return os << obj.getName() << ", form grade required to sign " << obj.getGradeSign() << ", form grade required to execute " << obj.getGradeExec();
}

AForm::~AForm() {}