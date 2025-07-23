/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:08:28 by babischa          #+#    #+#             */
/*   Updated: 2025/05/26 19:24:50 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"


void Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(std::string LastName)
{
    this->_lastName = LastName;
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhone(std::string phone)
{
    this->_phoneNumber = phone;
}

void Contact::setSecret(std::string secret)
{
    this->_darkestSecret = secret;
}


std::string Contact::getFirstName(void)
{
    return(this->_firstName);
}

std::string Contact::getLastName(void)
{
    return(this->_lastName);
}

std::string Contact::getNick(void)
{
    return(this->_nickname);
}

std::string Contact::getPhone(void)
{
    return(this->_phoneNumber);
}

std::string Contact::getSecret(void)
{
    return(this->_darkestSecret);
}
