#include "./Bureaucrat.hpp"

int main()
{
	std::cout << "# Default Bureaucrat" << std::endl;
	{
		Bureaucrat bureaucrat;
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# Named Bureaucrat" << std::endl;
	{
		Bureaucrat bureaucrat("bureaucrat", 130);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# ctor(grade 0)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# ctor(grade 151)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# increment(grade 1 -> 0)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 1);
		bureaucrat.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# decrement(grade 150 -> 151)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 150);
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
