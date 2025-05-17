#pragma

#include <limits>
#include <tuple>
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

    std::vector<Contact> searchContactList();
    std::tuple<bool, std::string> checkIsDuplicate(std::string phoneNumber, std::string name);

   public:
    void showMenu();

    void addContact();

    void updateContact();

    void searchContact();

    void deleteContact();

    void viewAllContactsInDetail();
};