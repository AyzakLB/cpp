/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:12 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:13 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string* stringPTR = &var;
    std::string& stringREF = var;

    // memory addresses
    std::cout << "memory address of var: " << &var << std::endl;
    std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "memory address of stringREF: " << &stringREF << std::endl;

    // values
    std::cout << "value of var: " << var << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}