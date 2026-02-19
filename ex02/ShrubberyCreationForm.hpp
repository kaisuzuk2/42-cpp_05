/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:46:36 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 12:08:48 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		void executeAction() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &);
		ShrubberyCreationForm(const ShrubberyCreationForm &);	
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		~ShrubberyCreationForm();
};

#endif