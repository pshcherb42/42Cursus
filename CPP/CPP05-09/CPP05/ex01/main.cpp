#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat m("Polina", 156);
	Form f("Maggot", 156, 50);
	std::cout << m << std::endl;
	std::cout << f << std::endl;
	m.signForm(f);

	Bureaucrat c("Mumu", 0);
	Form n("Mimi", 0, 2);
	std::cout << c << std::endl;
	std::cout << n << std::endl;
	c.signForm(n);

	Bureaucrat d("Drake", 30);
	Form r("Rihanna", 50, 80);

	std::cout << std::endl;
	std::cout << r << std::endl;
	std::cout << d << std::endl;

	std::cout << std::endl;

	d.signForm(r);

	
}