#pragma once

#include <exception>
#include <iostream>
#include <string>

#define BUREAUCRAT_MAX_GRADE 1
#define BUREAUCRAT_MIN_GRADE 150

class Form;

class Bureaucrat
{
 private:
	std::string _name;
	int _grade;

 public:
	Bureaucrat();
	Bureaucrat(
		const std::string &name,
		int grade
	);
	virtual ~Bureaucrat();

	Bureaucrat(
		const Bureaucrat &other
	);
	Bureaucrat &operator=(
		const Bureaucrat &other
	);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(
		class Form &form
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
	const Bureaucrat &bureaucrat
);
