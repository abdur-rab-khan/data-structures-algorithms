// CMS/includes/personalContact.hpp
#pragma once

#include "Contact.hpp"

enum class UpdationTypeForP {
    Name = 1,
    NickName,
    PhoneNumber,
    Email,
};

class PersonalContact : public Contact {
   private:
    std::string nickName;

   public:
    PersonalContact(std::string name, std::string nickName, std::string phoneNumber,
                    std::string email);

    void displayContactDetails() const override;

    void updateContact();
};