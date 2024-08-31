#include "./RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

void RobotomyRequestForm::executeAction(
) const
{
	std::cout
		<< "GGGGG ... ";
	std::srand(std::time(NULL));
	if ((std::rand() % 2) == 0) {
		std::cout
			<< this->_target
			<< " has been robotomized successfully."
			<< std::endl;
	} else {
		std::cout
			<< "the robotomy failed"
			<< std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(
) : AForm(ROBOTOMY_REQUEST_FORM_NAME, ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_SIGN, ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_EXECUTE),
		_target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(
	const std::string &target
) : AForm(ROBOTOMY_REQUEST_FORM_NAME, ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_SIGN, ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_EXECUTE),
		_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(
)
{
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm &other
) : AForm(other),
		_target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other
)
{
	AForm::operator=(other);
	if (this == &other) {
		return *this;
	}
	this->_target = other._target;
	return *this;
}

const std::string &RobotomyRequestForm::getTarget(
) const
{
	return this->_target;
}
