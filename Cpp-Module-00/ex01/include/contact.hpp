#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        // Contact(void);
        // ~Contact(void);
        void setFirstName(std::string firstName);
        void setLastName(std::string LastName);
        void setNickname(std::string nickname);
        void setPhone(std::string phone);
        void setSecret(std::string secret);

        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNick(void);
        std::string getPhone(void);
        std::string getSecret(void);
};

#endif
