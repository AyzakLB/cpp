#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    public:
        void setFirstName(const std::string& fn);
        void setLastName(const std::string& ln);
        void setNickName(const std::string& nn);
        void setPhoneNumber(const std::string& pn);
        void setDarkestSecret(const std::string& ds);
        const std::string& getFirstName(void) const;
        const std::string& getLastName(void) const;
        const std::string& getNickName(void) const;
        const std::string& getPhoneNumber(void) const;
        const std::string& getDarkestSecret(void) const;
};

#endif