/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:42 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:43 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "need 3 arguments" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string originalStr = av[2];
    std::string newStr = av[3];
    std::string line;
    std::string outFilename = filename + ".replace";

    if (originalStr.empty())
    {
        std::cerr << "no string to replace" << std::endl;
        return 1;
    }
    std::ifstream inputFile(filename.c_str());
    if (inputFile.is_open() == false)
    {
        std::cerr << "problem with opening files: " << filename << std::endl;
        return 1;
    }
    std::ofstream outputFile(outFilename.c_str());
    if (outputFile.is_open() == false)
    {
        inputFile.close();
        std::cerr << "problem with opening files: " << outFilename << std::endl;
        return 1;
    }
    while (std::getline(inputFile, line))
    {
        outputFile << myReplace(line, originalStr, newStr);
        if (inputFile.eof())
            break;
        else
            outputFile << '\n';
    }
    inputFile.close();
    outputFile.close();
    return 0;

}