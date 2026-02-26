/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:25:14 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 12:05:43 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():  _name("Default"), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade) {
	checkGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: grade too low");
}

const std::string &Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incGrade() {
	checkGrade(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::decGrade() {
	checkGrade(this->_grade + 1);
	this->_grade++;
}

void Bureaucrat::checkGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl; 
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os ,const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
