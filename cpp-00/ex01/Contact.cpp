#include "Contact.hpp"
////////////////////////////////////////////// SETTERS //////////////////////////////////////////////

void Contact::setFirstName(const std::string &fn)
{
    firstName = fn;
}

void Contact::setLastName(const std::string &ln)
{
    lastName = ln;
}

void Contact::setNickName(const std::string &nn)
{
    nickName = nn;
}

void Contact::setPhoneNumber(const std::string &pn)
{
    phoneNumber = pn;
}

void Contact::setDarkestSecret(const std::string &ds)
{
    darkestSecret = ds;
}
////////////////////////////////////////////// GETTERS //////////////////////////////////////////////

const std::string &Contact::getFirstName(void) const
{
    return firstName;
}

const std::string &Contact::getLastName(void) const
{
    return lastName;
}

const std::string &Contact::getNickName(void) const
{
    return nickName;
}

const std::string &Contact::getPhoneNumber(void) const
{
    return phoneNumber;
}

const std::string &Contact::getDarkestSecret(void) const
{
    return darkestSecret;
}
