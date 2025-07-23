/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:06:56 by babischa          #+#    #+#             */
/*   Updated: 2025/05/29 19:25:09 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
    std::cout << GREEN << "* * * HEAP ZOMBIE * * *" << RESET << std::endl;
    Zombie *heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete  heapZombie;

    std::cout << GREEN << "\n* * * STACK ZOMBIE * * *" << RESET << std::endl;
    randomChump("Stack Zombie");
}
