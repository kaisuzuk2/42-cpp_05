/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:09:23 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 12:21:52 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("unknown"), _target("Default target"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, const std::string &target, bool isSigned, int gradeToSign, int gradeToExecute): 
	_name(name), _target(target), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		checkGrade(this->_gradeToSign);
		checkGrade(this->_gradeToExecute);
}

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute): 
	_name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
		checkGrade(this->_gradeToSign);
		checkGrade(this->_gradeToExecute);
}

AForm::AForm(const AForm &other): _name(other._name), _target(other._target),  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	*this = other;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form: grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form: grade too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form: form is not signed");
}

const char *AForm::AlreadySignedException::what() const throw() {
	return ("Form: already signed");
}

const std::string &AForm::getName() const {
	return (this->_name);
}

const std::string &AForm::getTarget() const {
	return (this->_target);
}

bool AForm::getIsSigned() const {
	return (this->_isSigned);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void AForm::checkGrade(int grade) const {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &b) {
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	if (this->_gradeToSign >= b.getGrade())
		this->_isSigned = true;
	else 
		throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &b) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (this->_gradeToExecute <  b.getGrade())
		throw AForm::GradeTooLowException();
	executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
	os << "---------- Form Information ----------" << std::endl;
	os << std::left << std::setw(20) << "Name" << ": " << f.getName() << std::endl;
	os << std::left << std::setw(20) << "Target" << ": " << f.getTarget() << std::endl;
	os << std::left << std::setw(20) << "Signed" << ": " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	os << std::left << std::setw(20) << "Grade to sign" << ": " << f.getGradeToSign() << std::endl;
	os << std::left << std::setw(20) << "Grade to execute" << ": " << f.getGradeToExecute() << std::endl;
	return (os);
}
