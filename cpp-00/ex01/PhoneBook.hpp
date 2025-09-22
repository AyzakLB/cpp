#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    Contact contactList[8];
    size_t contactCount;
    size_t currIndex;
    bool displayContact(int index);
    std::string getInput(const std::string& prompt);
    public:
        PhoneBook();
        bool add();
        bool search();
};

bool checkEof(std::string& input);

#endif