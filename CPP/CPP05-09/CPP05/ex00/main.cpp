#include "Bureaucrat.hpp"

int main() {
	Bureaucrat m("Polina", 156);

	std::cout << m << std::endl << std::endl;

	m.incrementGrade(10);
	std::cout << m << std::endl << std::endl;
	m.decrementGrade(100);
	std::cout << m << std::endl << std::endl;
}