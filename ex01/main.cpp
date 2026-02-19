/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 08:38:15 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 09:12:03 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "========== Form default constructor ==========" << std::endl;
		Form defo;
		std::cout << defo << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "========== argument constructor ==========" << std::endl;
		std::cout << "***default" << std::endl;
		Form a("Form a", false, 75, 75);
		std::cout << a << std::endl;
		std::cout << std::endl;

		Form b("Form b", true, 76, 76);
		std::cout << b << std::endl;
		std::cout << std::endl;

		Form c("Form c", 99, 99);
		std::cout << c << std::endl;
		std::cout << std::endl;

		std::cout << "*** exception" << std::endl;
		try{
			Form d("Form d", true, -1, 0);
			std::cout << d << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			Form e("Form e", 151, 200);
			std::cout << e << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl;
	{
		std::cout << "========== Form copy constructor ==========" << std::endl;
		Form a("Form a", 10, 20);
		Form b(a);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	
	std::cout << std::endl;

	{
		std::cout << "========== copy asignment ==========" << std::endl;
		Form a("Form a", 30, 40);
		Form b("Form b", true, 30, 40);
		
		a = b;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "========== ①sign test <success> ==========" << std::endl;
		try {
			Form a("Form a", 10, 10);
			Bureaucrat boss("Boss", 1);

			std::cout << boss << std::endl;
			std::cout << a << std::endl;
			boss.signForm(a);
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "========== ②sign test <success> ==========" << std::endl;
		try {
			Form a("Form a", 10, 10);
			Bureaucrat b("b", 10);

			std::cout << b << std::endl;
			std::cout << a << std::endl;
			b.signForm(a);
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "========== ③sign test <failue> ==========" << std::endl;
		try {
			Form a("Form a", 10, 10);
			Bureaucrat b("b", 11);

			std::cout << b << std::endl;
			std::cout << a << std::endl;
			b.signForm(a);
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
