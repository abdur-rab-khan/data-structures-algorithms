#include <iostream>
#include <limits>
#include <vector>

#include "../includes/Todo.hpp"
#include "../includes/TodoManager.hpp"

enum class Choice { Add = 1, Get, Update, Delete, Exit };

int main() {
    TodoManager todoManager;

    while (true) {
        int input;
        std::cout << "1. Add\n2. Get\n3. Update\n4. Delete\n5. Exit\nEnter choice: " << std::flush;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();  // reset the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');  // discard bad input.
            std::cout << "Invalid input. Please enter a number.\n";
            continue;  // go back to menu
        }

        switch (static_cast<Choice>(input)) {
            case (Choice::Add):
                todoManager.addTodo();
                break;

            case (Choice::Get):
                todoManager.getAllTodo();
                break;

            case (Choice::Update):
                todoManager.updateTodo();
                break;

            case (Choice::Delete):
                todoManager.removeTodo();
                break;

            case (Choice::Exit):
                return 0;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }
    return 0;
}