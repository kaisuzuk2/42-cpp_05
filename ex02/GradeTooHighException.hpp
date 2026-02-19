/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:37:10 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/18 12:02:16 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

#include <exception>

class GradeTooHighException: public std::exception {
	public:
		const char *what() const throw();
};

#endif
