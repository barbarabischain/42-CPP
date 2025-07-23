/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:43 by babischa          #+#    #+#             */
/*   Updated: 2025/05/26 19:18:05 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

# define BLUE			"\033[34m"
# define CYAN			"\033[36m"
# define BCYAN			"\033[1;36m"
# define BGREEN			"\033[1;32m"
# define GREEN			"\033[32m"
# define BMAGENTA		"\033[1;35m"
# define RED			"\033[1;31m"
# define RESET			"\033[0m"
# define YELLOW			"\033[33m"

class PhoneBook
{
    private:
        int     _contactCount;
        int     _currentIndex;
        Contact _contact[8];
        void    _displayTableColumns(void);
        void    _displayTableContent(void);
        void    _truncateName(std::string str);
        void    _displayContactDetails(int i);
        bool    _isNumeric(std::string str);

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact(void);
        void    searchContact(void);
};

#endif
