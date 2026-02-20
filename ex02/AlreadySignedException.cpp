/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlreadySignedException.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:08:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/20 10:13:31 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlreadySignedException.hpp"

const char *AlreadySignedException::what() const throw() {
	return ("AForm: already signed");
}
