/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormNotSignedException.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:08:28 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 08:13:44 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormNotSignedException.hpp"

const char *FormNotSignedException::what() const throw() {
	return ("AForm: form is not signed");
}
