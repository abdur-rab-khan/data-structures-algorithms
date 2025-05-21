#pragma once

#include <limits>
#include <memory>
#include <tuple>
#include <vector>

#include "BusinessContact.hpp"
#include "Contact.hpp"
#include "PersonalContact.hpp"

enum class ContactType { PersonalContact = 1, BusinessContact };

enum class MenuOptions {
    ADD_CONTACT = 1,
    UPDATE_CONTACT,
    DELETE_CONTACT,
    SEARCH_CONTACT,
    VIEW_ALL_CONTACT_DETAIL,
    EXIT
};

class ContactManager {
   private:
    std::vector<std::shared_ptr<Contact>> listContact;

    std::vector<std::shared_ptr<Contact>> searchContactList();
    std::tuple<bool, std::string> checkIsDuplicate(std::string phoneNumber, std::string name);

   public:
    void runApp();

    void addContact();

    void updateContact();

    void searchContact();

    void deleteContact();

    void viewAllContactsInDetail();
};