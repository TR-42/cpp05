#pragma once

#include <iostream>
#include <string>

#include "./Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "form"
#define DEFAULT_MIN_GRADE_TO_SIGN 10
#define DEFAULT_MIN_GRADE_TO_EXECUTE 10

class Form
{
 private:
	std::string _name;
	bool _isSigned;
	int _minGradeToSign;
	int _minGradeToExecute;

 public:
	Form();
	Form(
		const std::string &name,
		int minGradeToSign,
		int minGradeToExecute
	);
	Form(
		const std::string &name
	);
	~Form();

	Form(
		const Form &other
	);
	Form &operator=(
		const Form &other
	);

	const std::string &getName() const;
	bool isSigned() const;
	int getMinGradeToSign() const;
	int getMinGradeToExecute() const;

	void beSigned(
		const Bureaucrat &bureaucrat
	);

	class GradeTooHighException : public std::exception
	{
	 public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	 public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(
	std::ostream &os,
	const Form &form
);
