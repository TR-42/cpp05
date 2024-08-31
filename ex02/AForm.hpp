#pragma once

#include <iostream>
#include <string>

#include "./Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "form"
#define DEFAULT_MIN_GRADE_TO_SIGN 10
#define DEFAULT_MIN_GRADE_TO_EXECUTE 10

class AForm
{
 private:
	std::string _name;
	bool _isSigned;
	int _minGradeToSign;
	int _minGradeToExecute;

 protected:
	virtual void executeAction() const = 0;

 public:
	AForm();
	AForm(
		const std::string &name,
		int minGradeToSign,
		int minGradeToExecute
	);
	AForm(
		const std::string &name
	);
	virtual ~AForm();

	AForm(
		const AForm &other
	);
	AForm &operator=(
		const AForm &other
	);

	const std::string &getName() const;
	bool isSigned() const;
	int getMinGradeToSign() const;
	int getMinGradeToExecute() const;

	void beSigned(
		const Bureaucrat &bureaucrat
	);

	void execute(
		const Bureaucrat &executor
	) const;

	class NotSignedException : public std::exception
	{
	 public:
		virtual const char *what() const throw();
	};
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
	const AForm &form
);
