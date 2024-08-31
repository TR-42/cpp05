#pragma once

#include "./AForm.hpp"

#define PRESIDENTIAL_PARDON_FORM_NAME "presidential pardon"
#define PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_SIGN 25
#define PRESIDENTIAL_PARDON_FORM_MIN_GRADE_TO_EXECUTE 5

class PresidentialPardonForm : public AForm
{
 private:
	std::string _target;

 protected:
	virtual void executeAction() const;

 public:
	PresidentialPardonForm();
	PresidentialPardonForm(
		const std::string &target
	);
	~PresidentialPardonForm();

	PresidentialPardonForm(
		const PresidentialPardonForm &other
	);
	PresidentialPardonForm &operator=(
		const PresidentialPardonForm &other
	);

	const std::string &getTarget() const;
};
