// CMS/includes/contact.hpp
#pragma

#include <iostream>
#include <string>

class Contact {
   protected:
    std::string name;
    std::string phoneNumber;
    std::string email;

   public:
    virtual void displayContactDetails();

    std::string getName() const;

    std::string getPhoneNumber() const;

    virtual void updateContact();

    virtual ~Contact();
};