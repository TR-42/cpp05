#include "./Intern.hpp"

#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

#define CREATE_FORM_FUNC(className) \
	static AForm *create##className( \
		const std::string &target \
	) \
	{ \
		return new className(target); \
	}

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(
	const Intern &other
)
{
	(void)other;
}

Intern &Intern::operator=(
	const Intern &other
)
{
	(void)other;
	return (*this);
}

CREATE_FORM_FUNC(RobotomyRequestForm)
CREATE_FORM_FUNC(PresidentialPardonForm)
CREATE_FORM_FUNC(ShrubberyCreationForm)
static const struct {
	const std::string name;
	AForm *(*create)(const std::string &target);
} FORMS[] = {
	{ROBOTOMY_REQUEST_FORM_NAME, createRobotomyRequestForm},
	{PRESIDENTIAL_PARDON_FORM_NAME, createPresidentialPardonForm},
	{SHRUBBERY_CREATION_FORM_NAME, createShrubberyCreationForm}
};

AForm *Intern::makeForm(
	const std::string &formName,
	const std::string &target
)
{
	for (
		size_t i = 0;
		i < sizeof(FORMS) / sizeof(*FORMS);
		++i
	) {
		if (FORMS[i].name == formName) {
			return FORMS[i].create(target);
		}
	}

	return NULL;
}
