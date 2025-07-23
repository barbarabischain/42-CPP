/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:25:12 by babischa          #+#    #+#             */
/*   Updated: 2025/06/26 14:41:55 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

# define BGREEN			"\033[1;32m"
# define GREEN			"\033[32m"
# define RED			"\033[1;31m"
# define RESET			"\033[0m"
# define YELLOW			"\033[33m"

class Zombie
{
    private:
    std::string _name;

    public:
    Zombie();
    ~Zombie(void);
    void    setname(std::string name);
    void    announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
