// CMS/src/contact.cpp
#include "../includes/Contact.hpp"

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::displayContactDetails() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl << std::endl;
}

void Contact::updateContact() {
    // Empty implementation
}