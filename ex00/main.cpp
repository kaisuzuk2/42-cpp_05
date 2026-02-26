/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:43:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 10:55:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void header(int id, const std::string &title) {
	std::cout << "\n========== " << id << ") " << title << " ==========" << std::endl;
} 

int main(void) {
	{
		Bureaucrat defo;
		
		header(0, "Default test");
		std::cout << defo << std::endl;

		std::cout << "*** increment" << std::endl;
		std::cout << "Expect grade = " << defo.getGrade() - 1 << std::endl;
		defo.incGrade();
		std::cout << "Result = " << defo << std::endl;
		
		std::cout << "*** decrement" << std::endl;
		std::cout << "Expect grade = " << defo.getGrade() + 1 << std::endl;
		defo.decGrade();
		std::cout << "Result = " << defo << std::endl;
	}

	std::cout << std::endl;

	{
		header(1, "Copy constructor test");
		Bureaucrat origin("copy", 10);
		Bureaucrat cpy(origin);
		
		std::cout << origin << std::endl;
		std::cout << cpy << std::endl;
	}

	std::cout << std::endl;

	{
		header(2, "Copy assginment test");
		Bureaucrat origin("origin", 10);
		Bureaucrat cpy("copy", 149);
		std::cout << origin << std::endl;
		std::cout << cpy << std::endl;

		std::cout << "*** copy assignment" << std::endl;
		cpy = origin;
		
		std::cout << origin << std::endl;
		std::cout << cpy << std::endl;
	}

	std::cout << std::endl;

	{
		header(3, "High constructor test");
		
		try {
			Bureaucrat high("HIGH", 0);
			std::cout << "This line should NOT be printed." << std::endl;
			std::cout << high << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		header(4, "Low constructor test");
		try {
			Bureaucrat low("Low", 151);
			std::cout << "This line should NOT be printed." << std::endl;
			std::cout << low << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		header(5, "incGrade test");
		Bureaucrat high("HIGH", 3);
		std::cout << high << std::endl;

		std::cout << "*** increment grade" << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				high.incGrade();
				std::cout << high << std::endl;
			}
			std::cout << "This line should NOT be printed." << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		header(6, "decGrade test");
		Bureaucrat low("Low", 147);
		std::cout << low << std::endl;

		std::cout << "*** decrement grade" << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				low.decGrade();
				std::cout << low << std::endl;
			}
			std::cout << "This line should NOT be printed." << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
 	}
}
