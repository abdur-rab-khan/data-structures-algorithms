// CMS/src/utils.cpp
#include "../includes/utils.hpp"

bool isValid(std::string content, std::regex match_regex) {
    return std::regex_match(content, match_regex);
}

std::string trim(const std::string& s) {
    auto start = std::find_if_not(s.begin(), s.end(), ::isspace);
    auto end = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();
    return (start < end ? std::string(start, end) : "");
}

std::string getHeadingMessage(std::string msg) {
    return "**************** " + msg + " ****************";
}

int getChoice(int max) {
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input. Please enter a number.");
    }

    if (max != 0 && choice > max)
        throw std::invalid_argument("Invalid choice. you reached the limit.");

    return choice;
}

std::string getStringFromUser(std::string msg, bool strict) {
    std::string content;

    std::cout << msg;
    std::cin.ignore();
    std::getline(std::cin, content);

    content = trim(content);

    if (strict && content.length() == 0) {
        throw std::invalid_argument("Invalid value, Enter correct value.");
    }

    return content;
}

std::string getPhoneNumberFromUser(std::string msg, bool strict) {
    std::string phoneNumber = "";
    std::regex number_regex(R"(^\d+$)");

    std::cout << msg;
    std::getline(std::cin, phoneNumber);

    phoneNumber = trim(phoneNumber);

    if (strict) {
        if (phoneNumber.length() == 0 || !isValid(phoneNumber, number_regex)) {
            std::cout << "Invalid email, Enter valid email address" << std::endl;
        }
    } else {
        if (phoneNumber.length() > 0 && !isValid(phoneNumber, number_regex)) {
            std::cout << "Invalid phone, Enter valid phone number" << std::endl;
        }
    }

    return phoneNumber;
}

std::string getEmailFromUser(std::string msg, bool strict) {
    std::string email;
    std::regex email_regex(R"(^[\w+.-]+@[\w+.-]+\.\w+$)");

    std::cout << msg;
    std::getline(std::cin, email);

    email = trim(email);

    if (strict) {
        if (email.length() == 0 || !isValid(email, email_regex)) {
            std::cout << "Invalid email, Enter valid email address" << std::endl;
        }
    } else {
        if (email.length() > 0 && !isValid(email, email_regex)) {
            std::cout << "Invalid email, Enter valid email address" << std::endl;
        }
    }

    return email;
}

std::string getWebsiteFromUser(std::string msg, bool strict) {
    std::string websiteUri;
    std::regex website_regex(R"(^(https?:\/\/)?(www\.)?[\w.-]+\.\w+$)");

    std::cout << msg;
    std::getline(std::cin, websiteUri);

    if (websiteUri.length() || !(std::regex_match(websiteUri, website_regex))) {
        throw std::invalid_argument("Invalid website, Enter correct website uri");
    }

    if (strict) {
        if (websiteUri.length() == 0 || !isValid(websiteUri, website_regex)) {
            std::cout << "Invalid uri, Enter valid website uri" << std::endl;
        }
    } else {
        if (websiteUri.length() > 0 && !isValid(websiteUri, website_regex)) {
            std::cout << "Invalid uri, Enter valid website uri" << std::endl;
        }
    }

    return websiteUri;
}