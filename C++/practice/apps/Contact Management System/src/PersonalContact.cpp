// CMS/src/personalContact.cpp
#include "../includes/PersonalContact.hpp"

#include "utils.cpp"

PersonalContact::PersonalContact(std::string name, std::string nickName, std::string phoneNumber,
                                 std::string email) {
    this->name = name;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

void PersonalContact::displayContactDetails() {
    std::cout << "Name: " << name << " ( " << nickName << " )" << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void PersonalContact::updateContact() {
    std::cout << "CHOOSE BETWEEN THEM ▽" << std::endl;
    std::cout << "1. Update Name" << std::endl;
    std::cout << "2. Update Nick Name" << std::endl;
    std::cout << "3. Update Phone Number" << std::endl;
    std::cout << "4. Update Email" << std::endl;

    int choice = getChoice();

    switch (static_cast<UpdationType>(choice)) {
        case UpdationType::Name: {
            std::string updatedName = getStringFromUser("Enter the updated name: ", true);

            name = updatedName;
            break;
        }
        case UpdationType::NickName: {
            std::string updatedNickName = getStringFromUser("Enter the updated nick name: ", true);

            nickName = updatedNickName;
            break;
        }
        case UpdationType::PhoneNumber: {
            std::string updateNumber = getPhoneNumber("Enter the update phone number: ", true);

            phoneNumber = updateNumber;
            break;
        }
        case UpdationType::Email: {
            std::string updatedEmail = getEmailFromUser("Enter the update email address: ", true);

            email = updatedEmail;
            break;
        }
        default:
            throw std::invalid_argument("Invalid input, Please enter correct choice.");
    }
}
