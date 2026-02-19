/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:58:42 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/19 13:00:47 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		void executeAction() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		~PresidentialPardonForm();
};

#endif