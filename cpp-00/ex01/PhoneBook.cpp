#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
    currIndex = 0;
}
////////////////////////////////////////////// ADD //////////////////////////////////////////////

std::string PhoneBook::getInput(const std::string& prompt)
{
    std::string input;

    std::cout << prompt << std::endl;
    while (true)
    {
        if (checkEof(input) == 0)
        {
            if (input.empty())
            {
                std::cout << "FIELD CAN'T BE EMPTY!!!" << std::endl;
                std::cout << prompt << std::endl;
            } else
                return input;
        } else
            return "";
    }
}

bool PhoneBook::add()
{
    contactList[currIndex].setFirstName(getInput("First Name: "));
    if (contactList[currIndex].getFirstName().empty())
        return 1;
    contactList[currIndex].setLastName(getInput("Last Name: "));
    if (contactList[currIndex].getLastName().empty())
        return 1;
    contactList[currIndex].setNickName(getInput("Nick Name: "));
    if (contactList[currIndex].getNickName().empty())
        return 1;
    contactList[currIndex].setPhoneNumber(getInput("Phone Number: "));
    if (contactList[currIndex].getPhoneNumber().empty())
        return 1;
    contactList[currIndex].setDarkestSecret(getInput("Darkest Secret: "));
    if (contactList[currIndex].getDarkestSecret().empty())
        return 1;
    if (contactCount <= 7)
        contactCount++;
    if (currIndex + 1 < 8)
        currIndex++;
    else
        currIndex = 0;
    return 0;
}
////////////////////////////////////////////// SEARCH //////////////////////////////////////////////

std::string checkStrLength(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    return str;
}

int getValidIndex(int contactCount)
{
    std::string indexString;
    int index;

    std::cout << "Enter the index of the contact you want to display: " << std::endl;
    while (true)
    {
        if (checkEof(indexString) == 0)
        {
            if (indexString.length() == 1 && isdigit(indexString[0]) && indexString[0] >= '1' && (indexString[0] - '0') <= contactCount)
            {
                index = indexString[0] - '0';
                return index - 1;
            }
            else
                std::cout << "NOT A VALID INDEX! provide a number between 1 and " << contactCount << std::endl;
        } else
            return -1;
        
    }
}

bool PhoneBook::displayContact(int index)
{
    if (index == -1)
        return 1;
    std::cout << "First Name: " << contactList[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contactList[index].getLastName() << std::endl;
    std::cout << "Nick Name: " << contactList[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contactList[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contactList[index].getDarkestSecret() << std::endl;
    return 0;
}

bool PhoneBook::search()
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nick Name" << std::endl;
    for (size_t i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << checkStrLength(contactList[i].getFirstName()) << "|";
        std::cout << std::setw(10) << checkStrLength(contactList[i].getLastName()) << "|";
        std::cout << std::setw(10) << checkStrLength(contactList[i].getNickName()) << std::endl;
    }
    if (contactCount == 0)
    {
        std::cout << "(No contacts to display)" << std::endl;
        return 0;
    }
    return(displayContact(getValidIndex(contactCount)));
}