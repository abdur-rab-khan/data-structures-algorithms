// CMS/src/personalContact.cpp
#include "../includes/PersonalContact.hpp"

#include "../includes/utils.hpp"

PersonalContact::PersonalContact(std::string name, std::string nickName, std::string phoneNumber,
                                 std::string email) {
    this->name = name;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

void PersonalContact::displayContactDetails() const {
    std::cout << "Name: " << name << (nickName.length() != 0 ? (" ( " + nickName + " )") : "")
              << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl << std::endl;
}

void PersonalContact::updateContact() {
    std::cout << "CHOOSE BETWEEN THEM ▽" << std::endl;
    std::cout << "1. Update Name" << std::endl;
    std::cout << "2. Update Nick Name" << std::endl;
    std::cout << "3. Update Phone Number" << std::endl;
    std::cout << "4. Update Email" << std::endl;

    int choice = getChoice();
    switch (static_cast<UpdationTypeForP>(choice)) {
        case UpdationTypeForP::Name: {
            std::string updatedName = getStringFromUser("Enter the updated name: ");
            name = updatedName;

            break;
        }
        case UpdationTypeForP::NickName: {
            std::string updatedNickName = getStringFromUser("Enter the updated nick name: ");
            nickName = updatedNickName;

            break;
        }
        case UpdationTypeForP::PhoneNumber: {
            std::string updateNumber =
                getPhoneNumberFromUser("Enter the update phone number: ", true);
            phoneNumber = updateNumber;

            break;
        }
        case UpdationTypeForP::Email: {
            std::string updatedEmail = getEmailFromUser("Enter the update email address: ");
            email = updatedEmail;

            break;
        }
        default:
            throw std::invalid_argument("Invalid input, Please enter correct choice.");
    }
}
