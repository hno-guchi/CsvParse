/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugMessage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/12/08 13:18:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGMESSAGE_HPP
# define DEBUGMESSAGE_HPP

#include <iostream>
#include <string>

typedef enum eMessageType {
	DEFAULT_CONSTRUCT,
	HAS_ARG_CONSTRUCT,
	COPY_CONSTRUCT,
	COPY_OPERATOR,
	DESTRUCT,
	NOT_MESSAGE
}	tMessageType;

void	debugMessage(const std::string &className, tMessageType type);

#endif
