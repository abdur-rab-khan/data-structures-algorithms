#pragma

#include "Contact.hpp"

class BusinessContact : public Contact {
   private:
    std::string company;
    std::string website;

   public:
    void displayContactDetails() override;

    void updateContact() override;
};