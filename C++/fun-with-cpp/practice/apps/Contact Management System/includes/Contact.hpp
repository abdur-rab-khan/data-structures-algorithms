// CMS/includes/contact.hpp
#pragma once

#include <iostream>
#include <string>

class Contact {
   protected:
    std::string name;
    std::string phoneNumber;
    std::string email;

   public:
    virtual void displayContactDetails() const;
    virtual void updateContact();

    std::string getName() const;
    std::string getPhoneNumber() const;

    virtual ~Contact() = default;
};