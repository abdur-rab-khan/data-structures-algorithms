#include <limits>
#include <string>

std::string getHeadingMessage(std::string msg) {
    return "**************** " + msg + " ****************";
}

int getChoice() {
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input. Please enter a number.");
    }

    return choice;
}