#pragma

#include <vector>

#include "Contact.hpp"

enum class ContactType { PersonalContact = 1, BusinessContact };

enum class MenuOptions {
    ADD_CONTACT = 1,
    UPDATE_CONTACT,
    DELETE_CONTACT,
    SEARCH_CONTACT,
    VIEW_ALL_CONTACT,
    VIEW_ALL_CONTACT_DETAIL
};

class ContactManager {
   private:
       std::vector<Contact> listContact;

   public:
    void showMenu() {}

    void addContact() {}

    void updateContact() {}

    void searchContact() {}

    void deleteContact() {}

    void viewAllContacts() {}

    void viewAllContactsInDetail() {}
};