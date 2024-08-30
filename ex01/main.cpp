#include "./Bureaucrat.hpp"
#include "./Form.hpp"

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
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# ctor(grade 151)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 151);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# increment(grade 1 -> 0)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 1);
		bureaucrat.incrementGrade();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "# decrement(grade 150 -> 151)" << std::endl;
	try {
		Bureaucrat bureaucrat("test", 150);
		bureaucrat.decrementGrade();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout
		<< std::endl
		<< std::endl;
	std::cout << "# ---------------- Form Validation Test ----------------" << std::endl;
	{
		try {
			Form("", BUREAUCRAT_MAX_GRADE, BUREAUCRAT_MAX_GRADE);
			std::cout << "Form created ... OK" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form("", BUREAUCRAT_MIN_GRADE, BUREAUCRAT_MIN_GRADE);
			std::cout << "Form created ... OK" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form("", BUREAUCRAT_MAX_GRADE - 1, BUREAUCRAT_MAX_GRADE);
			std::cout << "Form created ... expected error ... NG" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form("", BUREAUCRAT_MAX_GRADE, BUREAUCRAT_MAX_GRADE - 1);
			std::cout << "Form created ... expected error ... NG" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form("", BUREAUCRAT_MIN_GRADE + 1, BUREAUCRAT_MAX_GRADE);
			std::cout << "Form created ... expected error ... NG" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form("", BUREAUCRAT_MIN_GRADE, BUREAUCRAT_MIN_GRADE + 1);
			std::cout << "Form created ... expected error ... NG" << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout
		<< std::endl
		<< std::endl;
	std::cout << "# ---------------- Form Sign Test ----------------" << std::endl;
	{
		Form form("TestForm", 100, 99);
		Bureaucrat bureaucrat("TestBureaucrat", 101);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;

		std::cout
			<< std::endl;
		bureaucrat.incrementGrade();
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;

		std::cout
			<< std::endl;
		bureaucrat.incrementGrade();
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
	}

	return 0;
}
