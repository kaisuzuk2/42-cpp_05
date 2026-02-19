/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:46:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 12:05:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", "Default target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = getTarget() + "_shrubbery"; 
	std::ofstream ofs(filename.c_str());
	if (ofs.is_open())
		throw std::runtime_error("failed to open file");
	
	ofs << "       /\\" << std::endl;
	ofs << "      /**\\" << std::endl;
	ofs << "     /****\\" << std::endl;
	ofs << "    /******\\" << std::endl;
	ofs << "       ||" << std::endl;
	ofs << "       ||" << std::endl;
	
	ofs.close();
}