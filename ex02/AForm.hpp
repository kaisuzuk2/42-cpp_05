/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:09:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 12:23:46 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include "AlreadySignedException.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const std::string _target;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		void checkGrade(int grade) const;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string &name, const std::string &target, bool _isSigned, int gradeToSign, int gradeToExecute);
		AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		const std::string &getName() const;
		const std::string &getTarget() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &);
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
