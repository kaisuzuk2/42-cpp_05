/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:09:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/18 14:05:11 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <iostream>
#include <iomanip>

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const std::string &name, bool _isSigned, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string getName() const;
		const bool getIsSigned() const;
		const int getGradeToSign() const;
		const int getGradeToExecute() const;
		void checkGrade(int grade) const;
		void beSigned() const;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif