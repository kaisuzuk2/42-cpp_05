/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormNotSignedException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:08:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 08:13:05 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMNOTSIGNEDEXCEPTION_HPP
# define FORMNOTSIGNEDEXCEPTION_HPP

#include <exception>

class FormNotSignedException: public std::exception {
	const char *what() const throw();
};

#endif
