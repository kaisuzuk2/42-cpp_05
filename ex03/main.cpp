/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:35:29 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 09:42:38 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void header(const std::string &title) {
	std::cout << "\n========== " << title << "==========" << std::endl;
}

int main(void) {
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 75);
	Bureaucrat low("Low", 150);

	{
		header("0) Default constructor");
		ShrubberyCreationForm dshrub;
		RobotomyRequestForm drobo;
		PresidentialPardonForm dpresi;

		std::cout << dshrub << std::endl;
		std::cout << drobo << std::endl;
		std::cout << dpresi << std::endl;

	}

	{
		header("1) copy constructor");
		std::cout << "*** ShrubberyCreationForm" << std::endl;
		ShrubberyCreationForm ashrub("shrubbery");
		ShrubberyCreationForm bshrub(ashrub);
		std::cout << ashrub << std::endl;
		std::cout << bshrub << std::endl;

		std::cout << "*** RobotomyRequestForm" << std::endl;
		RobotomyRequestForm arobo("robo");
		RobotomyRequestForm brobo(arobo);
		std::cout << arobo << std::endl;
		std::cout << brobo << std::endl;

		std::cout << "*** PresidentialPardonForm" << std::endl;
		PresidentialPardonForm apresi("presidential");
		PresidentialPardonForm bpresi(apresi);
		std::cout << apresi << std::endl;
		std::cout << bpresi << std::endl;
	}

	{
		header("2) copy assignment");
		Bureaucrat boss("boss", 1);
		std::cout << "*** ShrubberyCreationForm" << std::endl;
		ShrubberyCreationForm ashrub("ashrub");
		ShrubberyCreationForm bshrub("bshrub");
		std::cout << ashrub << std::endl;
		std::cout << bshrub << std::endl;
		boss.signForm(ashrub);
		bshrub = ashrub;
		std::cout << ashrub << std::endl;
		std::cout << bshrub << std::endl;

		std::cout << "*** RobotomyRequestForm" << std::endl;
		RobotomyRequestForm arobo("arobo");
		RobotomyRequestForm brobo("brobo");
		std::cout << arobo << std::endl;
		std::cout << brobo << std::endl;
		boss.signForm(arobo);
		brobo = arobo;
		std::cout << arobo << std::endl;
		std::cout << brobo << std::endl;
		
		std::cout << "*** PresidentialPardonForm" << std::endl;
		PresidentialPardonForm apresi("apresi");
		PresidentialPardonForm bpresi("bpresi");
		std::cout << apresi << std::endl;
		std::cout << bpresi << std::endl;
		boss.signForm(apresi);
		bpresi = apresi;
		std::cout << apresi << std::endl;
		std::cout << bpresi << std::endl;
	}

	{
		header("3) Constructor forms");
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("marvin");
		PresidentialPardonForm presi("arthr");

		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << presi << std::endl;

	}

	ShrubberyCreationForm shrub("shrub");
	RobotomyRequestForm robo("robo");
	PresidentialPardonForm presi("presi");

	{
		header("4) Execute unsigned form -> should fail (FormNotSignedException)");
		boss.executeForm(shrub);
		boss.executeForm(robo);
		boss.executeForm(presi);
	}

	{
		header("2) sign tests");
		Bureaucrat shrubSign("Shurb", 145);
		Bureaucrat roboSign("robo", 72);
		Bureaucrat presiSign("presi", 25);
		
		// shrub: sign 145
		low.signForm(shrub); // fail
		std::cout << std::endl;
		shrubSign.signForm(shrub); // success
		std::cout << std::endl;
		mid.signForm(shrub); // fail(already signed)
		std::cout << std::endl;

		// robo: sign 72
		mid.signForm(robo); // fail
		std::cout << std::endl;
		roboSign.signForm(robo); // success
		std::cout << std::endl;
		boss.signForm(robo); // fail(already signed)
		std::cout << std::endl;

		// presi: sign 25
		mid.signForm(presi); // fail
		std::cout << std::endl;
		presiSign.signForm(presi); // success
		std::cout << std::endl;
		boss.signForm(presi); // success
		std::cout << std::endl;
	
	}
	
	{
		header("3) Execute tests");
		Bureaucrat shrubExec("shrub", 137);
		Bureaucrat roboExec("robo", 45);
		Bureaucrat presiExec("presi", 5);

		// shrub: exec 137
		low.executeForm(shrub); // fail (too low)
		std::cout << std::endl;
		shrubExec.executeForm(shrub); // success -> create file
		std::cout << std::endl;

		// robo: exec 45
		mid.executeForm(robo); // fail (too low)
		std::cout << std::endl;
		roboExec.executeForm(robo); // success (50%)
		std::cout << std::endl;

		// presi: exec 5
		mid.executeForm(presi); // fail ( too low)
		std::cout << std::endl;
		presiExec.executeForm(presi); // success
		std::cout << std::endl;
		
	}
}
