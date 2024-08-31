#pragma once

#include "./AForm.hpp"

#define SHRUBBERY_CREATION_FORM_NAME "shrubbery creation"
#define SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_SIGN 145
#define SHRUBBERY_CREATION_FORM_MIN_GRADE_TO_EXECUTE 137

class ShrubberyCreationForm : public AForm
{
 private:
	std::string _target;

 protected:
	virtual void executeAction() const;

 public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(
		const std::string &target
	);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(
		const ShrubberyCreationForm &other
	);
	ShrubberyCreationForm &operator=(
		const ShrubberyCreationForm &other
	);

	const std::string &getTarget() const;
};
