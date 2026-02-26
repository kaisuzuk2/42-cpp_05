/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:25:09 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 12:20:49 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		void checkGrade(int grade) const;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};

		const std::string &getName() const ;
		int getGrade() const ;
		void incGrade();
		void decGrade();
		void signForm(AForm &) const;
		void executeForm(AForm const & form) const;
}; 

std::ostream &operator<<(std::ostream &os, const Bureaucrat &);

#endif
