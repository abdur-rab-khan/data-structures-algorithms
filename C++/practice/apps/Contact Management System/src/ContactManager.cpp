// CMS/src/contactManager.cpp
#include "../includes/ContactManager.hpp"

#include <limits>

#include "../includes/BussinessContact.hpp"
#include "../includes/PersonalContact.hpp"
#include "utils.cpp"

void ContactManager::showMenu() {
    std::cout << "Contact Management System" << std::endl;
    std::cout << getHeadingMessage("MAIN MENU") << std::endl;
    std::cout << "1. Add new Contact " << std::endl;
    std::cout << "2. Update Existing Contact " << std::endl;
    std::cout << "3. Delete Existing Contact " << std::endl;
    std::cout << "4. Search Contact " << std::endl;
    std::cout << "5. View All Contacts " << std::endl;

    int choice = getChoice();

    switch (static_cast<MenuOptions>(choice)) {
        case MenuOptions::ADD_CONTACT:
            addContact();
            break;
        case MenuOptions::UPDATE_CONTACT:
            updateContact();
            break;
        case MenuOptions::DELETE_CONTACT:
            deleteContact();
            break;
        case MenuOptions::SEARCH_CONTACT:
            searchContact();
            break;
        case MenuOptions::VIEW_ALL_CONTACT_DETAIL:
            viewAllContactsInDetail();
            break;
        default:
            throw std::invalid_argument("Invalid input. Please enter a correct choice.");
    }
}

void ContactManager::addContact() {
    ContactType choice;

    std::string name;
    std::string phoneNumber;
    std::string email;

    std::cout << getHeadingMessage("Choose the type of phone number: ");

    std::cout << "1. Personal Contact" << std::endl;
    std::cout << "2. Business Contact" << std::endl;

    choice = static_cast<ContactType>(getChoice());

    if (choice == ContactType::PersonalContact) {
        std::string nickName;

        std::cout << getHeadingMessage("ADD NEW PERSONAL CONTACT") << std::endl;

        name = getStringFromUser("Enter the name: ");
        nickName = getStringFromUser("Enter the nick name: ");
        phoneNumber = getStringFromUser("Enter the phone number: ");
        email = getStringFromUser("Enter the email address: ");

        PersonalContact personalContact(name, nickName, phoneNumber, email);

        listContact.emplace_back(personalContact);
    } else if (choice == ContactType::BusinessContact) {
        std::string company;
        std::string website;

        std::cout << getHeadingMessage("ADD NEW BUSINESS CONTACT") << std::endl;

        name = getStringFromUser("Enter the name: ");
        phoneNumber = getStringFromUser("Enter the phone number: ");
        email = getStringFromUser("Enter the email address: ");
        company = getStringFromUser("Enter the email address: ");
        website = getStringFromUser("Enter the website uri: ");

        BusinessContact businessContact(name, phoneNumber, email, company, website);

        listContact.emplace_back(businessContact);
    } else {
        throw std::invalid_argument("Invalid choice, Enter correct choice");
    }

    std::cout << "Add Name" << std::endl;

    std::string name = getStringFromUser("Enter the name: ");
    std::cout << "Nick Name" << std::endl;
    std::cout << "Update Email" << std::endl;
    std::cout << "Update Phone Number" << std::endl;
}

void ContactManager::updateContact() {}

void ContactManager::searchContact() {}

void ContactManager::viewAllContactsInDetail() {}

void ContactManager::viewAllContacts() {}