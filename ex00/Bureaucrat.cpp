#include "./Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

Bureaucrat::Bureaucrat(
) : _name("default"),
		_grade(BUREAUCRAT_MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(
	const std::string &name,
	int grade
) : _name(name),
		_grade(grade)
{
	if (grade < BUREAUCRAT_MAX_GRADE)
		throw GradeTooHighException();
	else if (BUREAUCRAT_MIN_GRADE < grade)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(
)
{
}

Bureaucrat::Bureaucrat(
	const Bureaucrat &other
) : _name(other._name),
		_grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(
	const Bureaucrat &other
)
{
	if (this == &other) {
		return *this;
	}

	this->_name = other._name;
	this->_grade = other._grade;

	return *this;
}

const std::string &Bureaucrat::getName(
) const
{
	return this->_name;
}

int Bureaucrat::getGrade(
) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(
)
{
	int nextState = this->_grade - 1;
	if (nextState < BUREAUCRAT_MAX_GRADE)
		throw GradeTooHighException();
	this->_grade = nextState;
}

void Bureaucrat::decrementGrade(
)
{
	int nextState = this->_grade + 1;
	if (BUREAUCRAT_MIN_GRADE < nextState)
		throw GradeTooLowException();
	this->_grade = nextState;
}

std::ostream &operator<<(
	std::ostream &os,
	const Bureaucrat &bureaucrat
)
{
	os
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return os;
}
