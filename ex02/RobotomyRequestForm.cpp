/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:06:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 09:31:18 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", "Default target", kSignGrade, kExecGrade) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", target, kSignGrade, kExecGrade) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
	std::srand(std::time(0));
	std::cout << "*** drilling noises *** " << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() <<  " robotomy failed." << std::endl;
}
