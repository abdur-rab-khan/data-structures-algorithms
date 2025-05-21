// CMS/src/BusinessContact.cpp

#include "../includes/BusinessContact.hpp"

#include "../includes/utils.hpp"

BusinessContact::BusinessContact(std::string name, std::string phoneNumber, std::string email,
                                 std::string company, std::string website) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->company = company;
    this->website = website;
}

void BusinessContact::displayContactDetails() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Company Name: " << company << std::endl;
    std::cout << "Website Name: " << website << std::endl << std::endl;
}

void BusinessContact::updateContact() {
    std::cout << "CHOOSE BETWEEN THEM ▽" << std::endl;
    std::cout << "1. Update Name" << std::endl;
    std::cout << "2. Update Phone Number" << std::endl;
    std::cout << "3. Update Email" << std::endl;
    std::cout << "4. Update Company Name" << std::endl;
    std::cout << "5. Update Website Name" << std::endl;

    int choice = getChoice();
    switch (static_cast<UpdationTypeForB>(choice)) {
        case UpdationTypeForB::Name: {
            std::string updatedName = getStringFromUser("Enter the updated name: ");
            name = updatedName;

            break;
        }
        case UpdationTypeForB::PhoneNumber: {
            std::string updateNumber = getPhoneNumberFromUser("Enter the update phone number: ");
            phoneNumber = updateNumber;

            break;
        }
        case UpdationTypeForB::Email: {
            std::string updatedEmail = getEmailFromUser("Enter the update email address: ");
            email = updatedEmail;

            break;
        }
        case UpdationTypeForB::Company: {
            std::string updatedCompany = getStringFromUser("Enter the updated company name: ");
            company = updatedCompany;

            break;
        }
        case UpdationTypeForB::Website: {
            std::string updatedWebsite = getWebsiteFromUser("Enter the updated website uri: ");
            website = updatedWebsite;

            break;
        }
        default:
            throw std::invalid_argument("Invalid input, Please enter correct choice.");
    }
}
