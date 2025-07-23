/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:57:56 by babischa          #+#    #+#             */
/*   Updated: 2025/05/26 18:16:33 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/phonebook.hpp"

#include <iostream>

void displayMenu() {
    std::cout << CYAN << "***********************************************\n";
    std::cout << "*           WELCOME TO MY PHONEBOOK           *\n";
    std::cout << "***********************************************\n";
    std::cout << "*                                             *\n";
    std::cout << "*   Type " << BCYAN << "ADD " << RESET << CYAN << "     ➤ to add a new contact      *\n";
    std::cout << "*   Type " << BCYAN << "SEARCH " << RESET << CYAN << "  ➤ to search saved contacts  *\n";
    std::cout << "*   Type " << BCYAN << "EXIT " << RESET << CYAN << "    ➤ to quit the program       *\n";
    std::cout << "*                                             *\n";
    std::cout << "***********************************************\n";
    std::cout << "Please enter a command: " << RESET;
}

void displayGoodbye(void)
{
    std::cout << CYAN << "\n***********************************************\n";
    std::cout << "*                GoodBye! =^.^=               *\n";
    std::cout << "***********************************************" << RESET << std::endl;
}


int main(void)
{
    PhoneBook newPhone;
    std::string command;

    while(1)
    {
        displayMenu();
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        else if (command == "ADD")
            newPhone.addContact();
        else if (command == "SEARCH")
            newPhone.searchContact();
        else
            std::cout << RED << "Invalid command!\n" << RESET;
    }
    displayGoodbye();
    return 0;
}
