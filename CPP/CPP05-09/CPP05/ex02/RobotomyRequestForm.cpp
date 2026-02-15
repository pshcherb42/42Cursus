#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), _target(other._target) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	AForm::performChecks(executor);

	srand(time(0));
	int randoNum = rand() % 2;
	std::cout << "DRRRRRRRRRRRDRRRDRRR!!!!!!!!!" << std::endl;
	if (randoNum == 1)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed..." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}