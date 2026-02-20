/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:19:44 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/18 12:02:18 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException: public std::exception {
	const char *what() const throw();	
};

#endif
