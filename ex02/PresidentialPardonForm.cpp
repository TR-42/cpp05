#include "./PresidentialPardonForm.hpp"

void PresidentialPardonForm::executeAction(
) const
{
	std::cout
		<< this->_target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
) : AForm(PRESIDENTIAL_PARDON_FORM_NAME, PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_SIGN, PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_EXECUTE),
		_target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const std::string &target
) : AForm(PRESIDENTIAL_PARDON_FORM_NAME, PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_SIGN, PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_EXECUTE),
		_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(
)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other
) : AForm(other),
		_target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other
)
{
	AForm::operator=(other);
	if (this == &other) {
		return *this;
	}
	this->_target = other._target;
	return *this;
}

const std::string &PresidentialPardonForm::getTarget(
) const
{
	return this->_target;
}
