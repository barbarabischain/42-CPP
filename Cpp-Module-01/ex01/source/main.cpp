/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:06:56 by babischa          #+#    #+#             */
/*   Updated: 2025/06/26 14:34:53 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
    int         n = 5;
    Zombie      *horde;
    std::string name = "Bob, the rotten head";

    horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;
}
