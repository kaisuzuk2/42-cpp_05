/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:58:44 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 13:03:14 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", "Default target", 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", target, 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}