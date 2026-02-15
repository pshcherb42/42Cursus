/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:22:10 by pshcherb          #+#    #+#             */
/*   Updated: 2025/06/26 12:27:50 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) 
{
    int     i;
    int     j;

    i = 1;
    (void)argv;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
        return (0);
    }
    else
    {
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
                j++;
            }
            i++;
        }
        std::cout << '\n';
    }
}