/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:39 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:40 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

std::string myReplace(std::string line, std::string originalStr, std::string newStr)
{
    size_t pos;
    int ogStrLen = originalStr.length();
    std::string newLine;

    while ((pos = line.find(originalStr, 0)) != std::string::npos)
    {
        newLine += line.substr(0, pos) + newStr;
        line = line.erase(0, pos + ogStrLen);
    }
    return newLine + line;
}