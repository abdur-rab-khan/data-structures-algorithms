#include "../includes/ContactManager.hpp"

#include <limits>

#include "utils.cpp"

enum class MenuOptions {
    ADD_CONTACT = 1,
    UPDATE_CONTACT,
    DELETE_CONTACT,
    SEARCH_CONTACT,
    VIEW_ALL_CONTACT,
    VIEW_ALL_CONTACT_DETAIL
};

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
            searchContact();
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
    std::cout << getHeadingMessage("ADD NEW CONTACT") << std::endl;
}