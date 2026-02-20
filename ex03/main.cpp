/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:58:45 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 13:07:38 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void header(const std::string &title) {
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main(void) {
	Intern intern;

	{
		header("0) success test");
		try {
			AForm *f1 = intern.makeForm("shrubbery creation", "target");
			if (f1) {
				std::cout << *f1 << std::endl;
				delete f1;
			}
			AForm *f2 = intern.makeForm("robotomy request", "target");
			if (f2) {
				std::cout << *f2 << std::endl;
				delete f2;
			}
			AForm *f3 = intern.makeForm("presidential pardon", "target");
			if (f3) {
				std::cout << *f3 << std::endl;
				delete f3;
			}
		} catch(std::bad_alloc &e) {
			std::cout << " Fatal: out of memory: " << e.what() << std::endl;
		}
	}

	{
		header("1) fail test");
		try {
			AForm *f1 = intern.makeForm("noexist", "target");
			if (f1) {
				std::cout << *f1 << std::endl;
				delete f1;
			}
			AForm *f2 = intern.makeForm("shrubbery creationn", "taret");
			if (f2) {
				std::cout << *f2 << std::endl;
				delete f2;
			}
			AForm *f3 = intern.makeForm("shrubbery creatio", "target");
			if (f3) {
				std::cout << *f3 << std::endl;
				delete f3;
			}
   		} catch (std::bad_alloc &e) {
			std::cout << "Fatal: out of memory: " << e.what() << std::endl;
		}
	}
}
