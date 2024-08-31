#include <cstdlib>

#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

int main(
	int argc,
	char **argv
)
{
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <target> <score>" << std::endl;
		return 1;
	}

	std::string target(argv[1]);
	int score;

	if (target.empty()) {
		std::cerr << "Invalid argv[1]" << std::endl;
		return 1;
	}

	try {
		score = std::atoi(argv[2]);
	} catch (const std::exception &e) {
		std::cerr << "Invalid argv[2]" << std::endl;
		return 1;
	}

	try {
		Bureaucrat bureaucrat("bureaucrat", score);

		try {
			std::cout << "# PresidentialPardonForm" << std::endl;
			PresidentialPardonForm form(target);
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		try {
			std::cout << "# RobotomyRequestForm" << std::endl;
			RobotomyRequestForm form(target);
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		try {
			std::cout << "# ShrubberyCreationForm" << std::endl;
			ShrubberyCreationForm form(target);
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
