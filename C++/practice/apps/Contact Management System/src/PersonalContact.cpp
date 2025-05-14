// CMS/src/personalContact.cpp
#include "../includes/PersonalContact.hpp"

#include "utils.cpp"

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
        case UpdationType::Name:
            break;
        case UpdationType::NickName:
            break;
        case UpdationType::PhoneNumber:
            break;
        case UpdationType::Email:
            break;
    }
}