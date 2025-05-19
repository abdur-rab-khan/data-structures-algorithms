// CMS/src/contactManager.cpp
#include "../includes/ContactManager.hpp"

#include "../includes/utils.hpp"

void ContactManager::showMenu() {
    std::cout << "Contact Management System" << std::endl;

    while (true) {
        std::cout << getHeadingMessage("MAIN MENU") << std::endl;
        std::cout << "1. Add new Contact " << std::endl;
        std::cout << "2. Update Existing Contact " << std::endl;
        std::cout << "3. Delete Existing Contact " << std::endl;
        std::cout << "4. Search Contact " << std::endl;
        std::cout << "5. View All Contacts " << std::endl;
        std::cout << "6. Exit" << std::endl;
        int choice = getChoice();

        try {
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
                case MenuOptions::EXIT:
                    return;
                default:
                    std::cout << "Invalid input. Please enter a correct choice." << std::endl;
            }
        } catch (std::invalid_argument e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void ContactManager::addContact() {
    ContactType choice;

    std::string name;
    std::string phoneNumber;
    std::string email;

    std::cout << getHeadingMessage("CHOOSE THE TYPE OF NUMBER:") << std::endl;

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

        // Checking contact is already exits.
        std::tuple<bool, std::string> isDuplicate = checkIsDuplicate(phoneNumber, name);

        if (std::get<0>(isDuplicate)) {
            throw std::invalid_argument(std::get<1>(isDuplicate));
        }

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

        // Checking contact is already exits.
        std::tuple<bool, std::string> isDuplicate = checkIsDuplicate(phoneNumber, name);

        if (std::get<0>(isDuplicate)) {
            throw std::invalid_argument(std::get<1>(isDuplicate));
        }

        BusinessContact businessContact(name, phoneNumber, email, company, website);
        listContact.emplace_back(businessContact);
    } else {
        throw std::invalid_argument("Invalid choice, Enter correct choice");
    }
}

void ContactManager::updateContact() {
    std::cout << getHeadingMessage("UPDATE THE CONTACT.") << std::endl;
    std::vector<std::shared_ptr<Contact>> searchResult = searchContactList();

    if (searchResult.size() == 0) {
        std::cout << "There are not contact with given name or phone" << std::endl;
        return;
    }

    // print the search result.
    for (int i = 0; i < searchResult.size(); i++) {
        std::cout << i + 1 << ": " << searchResult.at(i)->getName() << "  "
                  << searchResult.at(i)->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl << "Choose which one you want to update " << std::endl;
    int choice = getChoice(searchResult.size());

    // Update the details from the contact.
    searchResult.at(choice - 1)->updateContact();
}

std::vector<std::shared_ptr<Contact>> ContactManager::searchContactList() {
    if (listContact.size() == 0) {
        throw std::invalid_argument("No contact found.");
    }

    std::vector<std::shared_ptr<Contact>> searchResult;

    // get from user.
    std::string searchKey =
        getStringFromUser("Enter phone number of contact name for search. ", true);

    std::regex pattern(searchKey, std::regex_constants::icase);

    for (const std::shared_ptr<Contact>& c : listContact) {
        if (!std::regex_search(c->getName(), pattern) &&
            !std::regex_search(c->getPhoneNumber(), pattern))
            continue;

        searchResult.push_back(c);
    }

    return searchResult;
}

void ContactManager::searchContact() {
    std::cout << getHeadingMessage("SEARCH A CONTACT") << std::endl;
    std::vector<std::shared_ptr<Contact>> searchResult = searchContactList();

    if (searchResult.size() == 0) {
        std::cout << "There are not contact with given name or phone" << std::endl;
        return;
    }

    // print the search result.
    for (int i = 0; i < searchResult.size(); i++) {
        std::cout << i + 1 << ": " << searchResult.at(i)->getName() << "  "
                  << searchResult.at(i)->getPhoneNumber() << std::endl;
    }
}

void ContactManager::viewAllContactsInDetail() {
    if (listContact.size() == 0) {
        char choice;
        std::cout << "There are not contact to show, please create than come again." << std::endl;

        std::cout << "Do you want to create a new contact y/n." << std::endl;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Invalid choice.");
        }

        if (choice == 'y') {
            addContact();
            return;
        }
    }

    for (const std::shared_ptr<Contact>& c : listContact) {
        c->displayContactDetails();
    }
}

void ContactManager::deleteContact() {
    std::cout << getHeadingMessage("DELETE THE CONTACT.") << std::endl;
    std::vector<std::shared_ptr<Contact>> searchResult = searchContactList();

    if (searchResult.size() == 0) {
        std::cout << "There are not contact with given name or phone" << std::endl;
        return;
    }

    // print the search result.
    for (int i = 0; i < searchResult.size(); i++) {
        std::cout << i + 1 << ": " << searchResult.at(i)->getName() << "  "
                  << searchResult.at(i)->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl << "Choose which one you want to delete " << std::endl;
    int choice = getChoice(searchResult.size());

    // Delete the details from the contact.
    std::shared_ptr<Contact> choosenResult = searchResult.at(choice - 1);

    for (int i = 0; i < listContact.size(); i++) {
        if (choosenResult->getPhoneNumber() != listContact.at(i)->getPhoneNumber())
            continue;

        listContact.erase(listContact.begin());
        std::cout << "Contact is delete successfully." << std::endl;
        break;
    }
}

std::tuple<bool, std::string> ContactManager::checkIsDuplicate(std::string phoneNumber,
                                                               std::string name) {
    if (listContact.size() == 0)
        return std::make_tuple(false, "No contact found.");

    for (const std::shared_ptr<Contact> c : listContact) {
        std::string OName = c->getName();
        std::string OPhoneNumber = c->getPhoneNumber();

        if (OName == name) {
            return std::make_tuple(true, "Contact already exits with this name.");
        } else if (OPhoneNumber == phoneNumber) {
            return std::make_tuple(true, "Contact already exits with this number.");
        }
    }

    return std::make_tuple(false, "No duplicate found.");
}