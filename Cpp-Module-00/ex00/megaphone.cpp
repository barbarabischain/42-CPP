/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:29 by babischa          #+#    #+#             */
/*   Updated: 2025/05/28 16:41:35 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

void print_megaphone(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        std::cout << (char) std::toupper(str[i]);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        print_megaphone(argv[i]);
        if (argv[i + 1])
            std::cout << " ";
    }
        std::cout << std::endl;
    return (0);
}
