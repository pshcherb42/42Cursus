/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:02:35 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 20:43:46 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main() {

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << str << "\n";
    std::cout << *stringPTR << "\n"; 
    std::cout << stringREF << "\n";

    return (0);
}