#include "./ShrubberyCreationForm.hpp"

#include <fstream>

void ShrubberyCreationForm::executeAction(
) const
{
	std::ofstream file(this->_target + "_shrubbery", std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	// 原案はCopilot
	file
		<< "       _-_" << std::endl
		<< "    /~~   ~~\\" << std::endl
		<< " /~~         ~~\\" << std::endl
		<< "{               }" << std::endl
		<< " \\  _-     -_  /" << std::endl
		<< "   ~  \\\\ //  ~" << std::endl
		<< "_- -   | | _- _" << std::endl
		<< "  _ -  | |   -_" << std::endl
		<< "      // \\\\" << std::endl;
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(
) : AForm(SHRUBBERY_CREATION_FORM_NAME, SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_SIGN, SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_EXECUTE),
		_target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const std::string &target
) : AForm(SHRUBBERY_CREATION_FORM_NAME, SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_SIGN, SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_EXECUTE),
		_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(
)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &other
) : AForm(other),
		_target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other
)
{
	AForm::operator=(other);
	if (this == &other) {
		return *this;
	}

	this->_target = other._target;
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget(
) const
{
	return this->_target;
}
