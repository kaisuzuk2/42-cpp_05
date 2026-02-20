/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:18:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 13:02:01 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) const {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target) const {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string &target) const {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const {
	struct FormEntry {
		const char *formName;
		AForm *(Intern::*creator)(const std::string &target) const;
	};
	static const FormEntry table[] = {
		{"shrubbery creation", &Intern::createShrubbery}, 
		{"robotomy request", &Intern::createRobotomy}, 
		{"presidential pardon", &Intern::createPresidential}
	}; 
	const int size = sizeof(table) / sizeof(table[0]);
	
	for (int i = 0; i < size; i++)
	{
		if (form == table[i].formName) {
			std::cout << "Intern creates " << table[i].formName << "." << std::endl;
			return ((this->*table[i].creator)(target));
		}
	}
	std::cout << "intern error: unknown form \'" << form << "\'" << std::endl;
	return (NULL);
}
