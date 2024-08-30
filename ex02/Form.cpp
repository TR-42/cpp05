#include "./Form.hpp"

const char *Form::GradeTooHighException::what(
) const throw()
{
	return "Grade is too high (Form::GradeTooHighException)";
}

const char *Form::GradeTooLowException::what(
) const throw()
{
	return "Grade is too low (Form::GradeTooLowException)";
}

Form::Form(
) : _name(DEFAULT_FORM_NAME),
		_isSigned(false),
		_minGradeToSign(DEFAULT_MIN_GRADE_TO_SIGN),
		_minGradeToExecute(DEFAULT_MIN_GRADE_TO_EXECUTE)
{
}

Form::Form(
	const std::string &name,
	int minGradeToSign,
	int minGradeToExecute
) : _name(name),
		_isSigned(false),
		_minGradeToSign(minGradeToSign),
		_minGradeToExecute(minGradeToExecute)
{
	if (minGradeToSign < BUREAUCRAT_MAX_GRADE)
		throw GradeTooHighException();
	else if (BUREAUCRAT_MIN_GRADE < minGradeToSign)
		throw GradeTooLowException();

	if (minGradeToExecute < BUREAUCRAT_MAX_GRADE)
		throw GradeTooHighException();
	else if (BUREAUCRAT_MIN_GRADE < minGradeToExecute)
		throw GradeTooLowException();
}

Form::Form(
	const std::string &name
) : _name(name),
		_isSigned(false),
		_minGradeToSign(DEFAULT_MIN_GRADE_TO_SIGN),
		_minGradeToExecute(DEFAULT_MIN_GRADE_TO_EXECUTE)
{
}

Form::~Form(
)
{
}

Form::Form(
	const Form &other
) : _name(other._name),
		_isSigned(other._isSigned),
		_minGradeToSign(other._minGradeToSign),
		_minGradeToExecute(other._minGradeToExecute)
{
}

Form &Form::operator=(
	const Form &other
)
{
	if (this == &other) {
		return *this;
	}

	this->_name = other._name;
	this->_isSigned = other._isSigned;
	this->_minGradeToSign = other._minGradeToSign;
	this->_minGradeToExecute = other._minGradeToExecute;

	return *this;
}

const std::string &Form::getName(
) const
{
	return this->_name;
}

bool Form::isSigned(
) const
{
	return this->_isSigned;
}

int Form::getMinGradeToSign(
) const
{
	return this->_minGradeToSign;
}

int Form::getMinGradeToExecute(
) const
{
	return this->_minGradeToExecute;
}

void Form::beSigned(
	const Bureaucrat &bureaucrat
)
{
	if (bureaucrat.getGrade() <= this->_minGradeToSign) {
		this->_isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(
	std::ostream &os,
	const Form &form
)
{
	os << "Form[" << form.getName() << "]("
		 << "isSigned: " << std::boolalpha << form.isSigned()
		 << ", minGradeToSign: " << form.getMinGradeToSign()
		 << ", minGradeToExecute: " << form.getMinGradeToExecute()
		 << ")";
	return os;
}
