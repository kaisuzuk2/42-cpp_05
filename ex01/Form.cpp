/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:09:23 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 12:53:19 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("unknown"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, bool isSigned, int gradeToSign, int gradeToExecute): 
	_name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		checkGrade(this->_gradeToSign);
		checkGrade(this->_gradeToExecute);
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): 
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
		checkGrade(this->_gradeToSign);
		checkGrade(this->_gradeToExecute);
}

Form::Form(const Form &other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	*this = other;
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form: grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form: grade too low");
}

const std::string &Form::getName() const {
	return (this->_name);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::checkGrade(int grade) const {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &b) {
	if (this->_gradeToSign >= b.getGrade())
		this->_isSigned = true;
	else 
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "---------- Form Information ----------" << std::endl;
	os << std::left << std::setw(20) << "Name" << ": " << f.getName() << std::endl;
	os << std::left << std::setw(20) << "Signed" << ": " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	os << std::left << std::setw(20) << "Grade to sign" << ": " << f.getGradeToSign() << std::endl;
	os << std::left << std::setw(20) << "Grade to execute" << ": " << f.getGradeToExecute() << std::endl;
	return (os);
}
