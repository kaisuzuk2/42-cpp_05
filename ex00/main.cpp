/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:43:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 10:52:12 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	{
		Bureaucrat defo;
		
		std::cout << "========== Default test ==========" << std::endl;
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
		std::cout << "========== Copy constructor test ==========" << std::endl;
		Bureaucrat origin("copy", 10);
		Bureaucrat cpy(origin);
		
		std::cout << origin << std::endl;
		std::cout << cpy << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "========== Copy assignment constructor test ==========" << std::endl;
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
		std::cout << "========== High constructor test ==========" << std::endl;

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
		std::cout << "========= Low constructor test ==========" << std::endl;

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
		Bureaucrat high("HIGH", 3);
		std::cout << "========== High test ==========" << std::endl;
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
		Bureaucrat low("Low", 147);
		std::cout << "========== low test ==========" << std::endl;
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
