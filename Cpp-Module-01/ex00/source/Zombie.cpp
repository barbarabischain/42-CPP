/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:06:59 by babischa          #+#    #+#             */
/*   Updated: 2025/05/29 19:29:18 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) :_name(name)
{
    std::cout << _name << " is constructed." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " is destroyed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << RED << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
