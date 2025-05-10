#include "../includes/TodoManager.hpp"

enum class UpdateTodo { Update = 1, Completed };

std::string TodoManager::getContentFromUser() {
    std::string content;
    std::cout << "Enter you todo content to add it. ";
    std::getline(std::cin >> std::ws, content);

    return content.length() == 1 ? "" : content;
}

void TodoManager::printAllTodoContent() {
    std::cout << "------------------ ALL TODOS LIST --------------------" << std::endl;
    for (size_t i = 0; i < todos.size(); ++i) {
        std::cout << "Sr no. " << i + 1 << " " << todos.at(i).getContent() << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

void TodoManager::addTodo() {
    std::cout << "****************** ADD TODO *******************" << std::endl;

    std::string content = getContentFromUser();

    if (!content.empty()) {
        Todo todo(content);

        todos.emplace_back(todo);
        std::cout << ">>>>>>>>>>>> TODO IS ADDED SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
    } else {
        std::cout << "Invalid Request" << std::endl;
    }
};

void TodoManager::getAllTodo() {
    std::cout << "------------------ LIST OF TODOS -----------------" << std::endl;
    int counter = 1;
    for (const Todo& todo : todos) {
        std::cout << "Sr No. " << counter << std::endl;
        todo.getTodoProps();

        counter += 1;
    }
};

void TodoManager::updateTodo() {
    std::cout << "****************** UPDATE TODO ********************" << std::endl;

    int choice;
    std::cout << "------------------ CHOOSE BETWEEN THEM -----------------" << std::endl;
    printAllTodoContent();

    std::cout << "Enter the todo number that you want to change:-  ";
    std::cin >> choice;

    if (choice > todos.size()) {
        std::cout << "⚠️ INVALID REQUEST OUT OF RANGE..." << std::endl;
    } else {
        int chooseWhatToUpdate;

        std::cout << "--------------------- CHOOSE WHAT YOU WANT TO UPDATE "
                     "---------------------------"
                  << std::endl;
        std::cout << "1. Update the content of todo \n2. Todo is completed" << std::endl;
        std::cin >> chooseWhatToUpdate;

        switch (static_cast<UpdateTodo>(chooseWhatToUpdate)) {
            case (UpdateTodo::Completed): {
                todos.at(choice - 1).updateTodo("", true);
                break;
            }
            case (UpdateTodo::Update): {
                std::string content = getContentFromUser();

                if (!content.empty()) {
                    todos.at(choice - 1).updateTodo(content);
                } else {
                    std::cout << "Invalid Request, Todo content is empty..." << std::endl;
                    return;
                }
                break;
            }
            default: {
                std::cout << "Invalid choice... Please try again." << std::endl;
                return;
            }
        }

        std::cout << ">>>>>>>>>>>> TODO IS UPDATED SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
    }
};

void TodoManager::removeTodo() {
    std::cout << "****************** DELETE TODO *******************" << std::endl;

    std::cout << "------------------  SELECTED THAT YOU WANT TO DELETE -----------------"
              << std::endl;
    int choice;
    printAllTodoContent();

    std::cout << "Enter the todo number that you want to delete:-  ";
    std::cin >> choice;

    if (choice > todos.size()) {
        std::cout << "Invalid choice, out of range..." << std::endl;
        return;
    } else {
        todos.erase(todos.begin() + choice - 1);

        std::cout << ">>>>>>>>>>>> TODO IS REMOVE SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
    }
};