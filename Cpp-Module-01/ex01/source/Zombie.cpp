/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:06:59 by babischa          #+#    #+#             */
/*   Updated: 2025/06/26 14:41:01 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << _name << "BEWARE! A new zombie has been created!" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " is destroyed!" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << RED << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void    Zombie::setname(std::string name)
{
    this->_name = name;
}
