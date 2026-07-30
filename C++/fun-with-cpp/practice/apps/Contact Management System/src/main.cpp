#include <iostream>

#include "../includes/ContactManager.hpp"

int main() {
    try {
        ContactManager contactManager;
        contactManager.runApp();
    } catch (std::invalid_argument e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}