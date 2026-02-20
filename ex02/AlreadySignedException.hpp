/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlreadySignedException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:08:29 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 10:13:22 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALREADYSIGNEDEXCEPTION_HPP
# define ALREADYSIGNEDEXCEPTION_HPP

#include <exception>

class AlreadySignedException: public std::exception {
	public:
		const char *what() const throw();
}; 

#endif
