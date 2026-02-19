/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:09:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 08:40:56 by kaisuzuk         ###   ########.fr       */
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

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		void checkGrade(int grade) const;
	public:
		Form();
		Form(const std::string &name, bool _isSigned, int gradeToSign, int gradeToExecute);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
