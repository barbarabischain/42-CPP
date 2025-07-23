/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:39 by babischa          #+#    #+#             */
/*   Updated: 2025/05/28 11:33:45 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook()
{
    this->_contactCount = 0;
    this->_currentIndex = 0;
}

PhoneBook::~PhoneBook(){}

void    PhoneBook::_truncateName(std::string str)
{
    if (str.size() < 10)
        std::cout << std::setw(10) << str;
    else if (str.size() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << str;
}

void    PhoneBook::_displayContactDetails(int i)
{
    std::cout << BCYAN << "Name: " << RESET << _contact[i].getFirstName() << " " << _contact[i].getLastName() << std::endl;
    std::cout << BCYAN << "Nickname: " << RESET <<  _contact[i].getNick() << std::endl;
    std::cout << BCYAN << "DarkestSecret: " << RESET << _contact[i].getSecret() << std::endl;
    std::cout << BCYAN << "Phone Number: " << RESET << _contact[i].getPhone() << std:: endl;
}

// SEARCH
void    PhoneBook::_displayTableColumns(void)
{
    std::cout << BMAGENTA <<"\n*     Index|First Name| Last Name|  Nickname  *\n" << RESET;
}

void    PhoneBook::_displayTableContent(void)
{
    int max;

    if (_contactCount < 8)
        max = _contactCount;
    else
        max = 8;
    for (int i = 0; i < max; i++)
    {
        std::cout << "          " << i + 1 << "|";
        _truncateName(_contact[i].getFirstName());
        std::cout << "|";
        _truncateName(_contact[i].getLastName());
        std::cout << "|";
        _truncateName(_contact[i].getNick());
        std::cout << "\n";
    }
}

void PhoneBook::searchContact(void)
{
    std::string content;
    int         n;

    _displayTableColumns();
    _displayTableContent();
    std::cout << CYAN << "Select contact index: " << RESET;
    std::getline(std::cin, content);

    if (_isNumeric(content))
    {
        n = atoi(content.c_str()) - 1;
        if (n >= 0 && n < 8 && n < _contactCount)
        {
            _displayContactDetails(n);
            std::cout << GREEN << "Press any key to return to Menu"<< RESET << std::endl;
            std::cin.ignore();
        }
        else
            std::cout << RED <<"Invalid Index!\n" << RESET;
    }
    else
        std::cout << RED <<"Invalid Index!\n" << RESET;
    content.clear();
}

// ADD
std::string    addContent(std::string message)
{
    std::string content;

    while (content.empty())
    {
        std::cout << CYAN << message << RESET;
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Field cannot be empty!\n" << RESET;
    }
    return (content);
}

bool    PhoneBook::_isNumeric(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void    PhoneBook::addContact(void)
{
    std::string content;

    if (_contactCount >= 8)
		std::cout << GREEN << "Contact list full!\nReplacing the oldest entry with the new contact..." << RESET << std::endl;
    _currentIndex = _contactCount % 8;

    content = addContent("Enter first name: ");
    this->_contact[_currentIndex].setFirstName(content);
    content.clear();

    content = addContent("Enter last name: ");
    this->_contact[_currentIndex].setLastName(content);
    content.clear();

    content = addContent("Enter nickname: ");
    this->_contact[_currentIndex].setNickname(content);
    content.clear();

    content = addContent("Enter phone number: ");
    while (!_isNumeric(content))
    {
        content.clear();
        std::cout <<  RED << "Invalid Phone Number!\n" << RESET;
        content = addContent("Enter phone number: ");

    }
    this->_contact[_currentIndex].setPhone(content);
    content.clear();

    content = addContent("Enter darkest secret: ");
    this->_contact[_currentIndex].setSecret(content);
    content.clear();

    _currentIndex++;
    _contactCount++;
}
