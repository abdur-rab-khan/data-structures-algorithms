// CMS/includes/contact.hpp
#pragma

#include <iostream>
#include <string>

class Contact {
   protected:
    std::string name;
    int phoneNumber;
    std::string email;

   public:
    virtual void displayContactDetails();

    std::string getName() const;

    virtual void updateContact();

    virtual ~Contact();
};