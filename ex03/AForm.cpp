#include "./AForm.hpp"

const char *AForm::NotSignedException::what(
) const throw()
{
	return "Form is not signed (AForm::NotSignedException)";
}

const char *AForm::GradeTooHighException::what(
) const throw()
{
	return "Grade is too high (AForm::GradeTooHighException)";
}

const char *AForm::GradeTooLowException::what(
) const throw()
{
	return "Grade is too low (AForm::GradeTooLowException)";
}

AForm::AForm(
) : _name(DEFAULT_FORM_NAME),
		_isSigned(false),
		_minGradeToSign(DEFAULT_MIN_GRADE_TO_SIGN),
		_minGradeToExecute(DEFAULT_MIN_GRADE_TO_EXECUTE)
{
}

AForm::AForm(
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

AForm::AForm(
	const std::string &name
) : _name(name),
		_isSigned(false),
		_minGradeToSign(DEFAULT_MIN_GRADE_TO_SIGN),
		_minGradeToExecute(DEFAULT_MIN_GRADE_TO_EXECUTE)
{
}

AForm::~AForm(
)
{
}

AForm::AForm(
	const AForm &other
) : _name(other._name),
		_isSigned(other._isSigned),
		_minGradeToSign(other._minGradeToSign),
		_minGradeToExecute(other._minGradeToExecute)
{
}

AForm &AForm::operator=(
	const AForm &other
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

const std::string &AForm::getName(
) const
{
	return this->_name;
}

bool AForm::isSigned(
) const
{
	return this->_isSigned;
}

int AForm::getMinGradeToSign(
) const
{
	return this->_minGradeToSign;
}

int AForm::getMinGradeToExecute(
) const
{
	return this->_minGradeToExecute;
}

void AForm::beSigned(
	const Bureaucrat &bureaucrat
)
{
	if (bureaucrat.getGrade() <= this->_minGradeToSign) {
		this->_isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(
	const Bureaucrat &executor
) const
{
	if (!this->_isSigned) {
		throw AForm::NotSignedException();
	}

	if (executor.getGrade() <= this->_minGradeToExecute) {
		this->executeAction();
	} else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(
	std::ostream &os,
	const AForm &form
)
{
	os << "AForm[" << form.getName() << "]("
		 << "isSigned: " << std::boolalpha << form.isSigned()
		 << ", minGradeToSign: " << form.getMinGradeToSign()
		 << ", minGradeToExecute: " << form.getMinGradeToExecute()
		 << ")";
	return os;
}
