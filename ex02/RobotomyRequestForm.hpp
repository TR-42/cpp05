#pragma once

#include "./AForm.hpp"

#define ROBOTOMY_REQUEST_FORM_NAME "robotomy request"
#define ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_SIGN 72
#define ROBOTOMY_REQUEST_FORM_MIN_GRADE_TO_EXECUTE 45

class RobotomyRequestForm : public AForm
{
 private:
	std::string _target;

 protected:
	virtual void executeAction() const;

 public:
	RobotomyRequestForm();
	RobotomyRequestForm(
		const std::string &target
	);
	~RobotomyRequestForm();

	RobotomyRequestForm(
		const RobotomyRequestForm &other
	);
	RobotomyRequestForm &operator=(
		const RobotomyRequestForm &other
	);

	const std::string &getTarget() const;
};
