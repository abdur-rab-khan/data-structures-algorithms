// CMS/includes/personalContact.hpp
#pragma

#include "Contact.hpp"

enum class UpdationType {
    Name = 1,
    NickName,
    PhoneNumber,
    Email,
};

class PersonalContact : public Contact {
   private:
    std::string nickName;

   public:
    void displayContactDetails() override;

    void updateContact();
};