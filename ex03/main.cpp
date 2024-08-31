#include <cstdlib>

#include "./Intern.hpp"

int main(
	int argc,
	char **argv
)
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <formName> <target> <score>" << std::endl;
		return 1;
	}

	std::string formName(argv[1]);
	std::string target(argv[2]);
	int score;

	if (formName.empty()) {
		std::cerr << "Invalid argv[1]" << std::endl;
		return 1;
	}
	if (target.empty()) {
		std::cerr << "Invalid argv[2]" << std::endl;
		return 1;
	}

	try {
		score = std::atoi(argv[3]);
	} catch (const std::exception &e) {
		std::cerr << "Invalid argv[3]" << std::endl;
		return 1;
	}

	Intern intern;
	AForm *form = NULL;
	try {
		Bureaucrat bureaucrat("bureaucrat", score);

		try {
			form = intern.makeForm(formName, target);
			if (form == NULL) {
				std::cerr << "Failed to create form" << std::endl;
				return 1;
			}

			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete form;
			return 1;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	delete form;
	return 0;
}
