#include <unistd.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

enum class Choice {
    Add = 1,
    Get = 2,
    Update = 3,
    Delete = 4,
    Exit = 5,
};

std::string generateRandomID(size_t length = 12) {
    const std::string chars =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    // Use a random device and Mersenne Twister for strong randomness
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string id;
    for (size_t i = 0; i < length; ++i) {
        id += chars[dist(rng)];
    }

    return id;
}

class Todo {
   private:
    std::string id;
    std::string content;
    bool completed = false;

   public:
    std::string getContent() const { return content; }

    void addTodo(std::string content) {
        id = generateRandomID();
        this->content = content;
    }

    void getTodoProps() const {
        std::cout << "Content " << content << std::endl;
        std::cout << "Is Completed " << completed << std::endl << std::endl;
    }

    void updateTodo(std::string content = "", bool isCompleted = false) {
        if (!content.empty()) {
            this->content = content;
        }

        if (isCompleted != completed) {
            this->completed = isCompleted;
        }
    }
};

class TodoManger {
   private:
    std::vector<Todo> todos;

    // HELPER FUNCTIONS
    std::string getContentFromUser() {
        std::string content;
        std::cout << "Enter you todo content to add it. ";
        std::getline(std::cin >> std::ws, content);

        if (content.length() == 1) {
            return "";
        }

        return content;
    }

    void printAllTodoContent() {
        std::cout << "------------------ ALL TODOS LIST --------------------" << std::endl;
        for (int i = 0; i < todos.size(); i++) {
            std::cout << "Sr no. " << i + 1 << " " << todos.at(i).getContent() << std::endl;
        }
        std::cout << "-----------------------------------------------" << std::endl;
    };

   public:
    void addTodo() {
        std::string content = getContentFromUser();

        if (!content.empty()) {
            Todo todo;
            todo.addTodo(content);

            todos.push_back(todo);
            std::cout << ">>>>>>>>>>>> TODO IS ADDED SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
        } else {
            std::cout << "Invalid Request" << std::endl;
        }
    }

    void getAllTodo() {
        std::cout << "------------------ LIST OF TODOS -----------------" << std::endl;
        int counter = 1;
        for (const Todo& todo : todos) {
            std::cout << "Sr No. " << counter << std::endl;
            todo.getTodoProps();

            counter += 1;
        }
    }

    void updateTodo() {
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
            std::cout << "1. Todo is completed\n2. Update the content of todo" << std::endl;
            std::cin >> chooseWhatToUpdate;

            if (chooseWhatToUpdate > 2 || chooseWhatToUpdate <= 0)
                return;

            if (chooseWhatToUpdate == 1) {
                todos.at(choice - 1).updateTodo("", true);
            } else {
                std::string content = getContentFromUser();

                if (!content.empty()) {
                    todos.at(choice - 1).updateTodo(content);
                } else {
                    std::cout << "⚠️ Invalid Request in correct content" << std::endl;
                }
            }

            std::cout << ">>>>>>>>>>>> TODO IS UPDATED SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
        }
    }

    void removeTodo() {
        std::cout << "------------------  SELECTED THAT YOU WANT TO DELETE -----------------"
                  << std::endl;
        int choice;
        printAllTodoContent();

        std::cout << "Enter the todo number that you want to delete:-  ";
        std::cin >> choice;

        if (choice > todos.size()) {
            std::cout << "⚠️ INVALID REQUEST OUT OF RANGE..." << std::endl;
            return;
        } else {
            todos.erase(todos.begin() + choice - 1);

            std::cout << ">>>>>>>>>>>> TODO IS REMOVE SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
        }
    }
};

int main() {
    std::vector<Todo> todo;
    std::unique_ptr<TodoManger> todoManger = std::make_unique<TodoManger>();

    while (true) {
        int choice;
        std::cout << "----------------- CHOOSE BETWEEN THEM ----------------------" << std::endl;
        std::cout << "1. To add new todo.\n2. Get All Todos.\n3. Update existing todo.\n4. Delete "
                     "todo.\n5. Exit"
                  << std::endl;

        std::cout << "Enter you choice: ";
        std::cin >> choice;
        Choice userChoice = static_cast<Choice>(choice);

        switch (userChoice) {
            case (Choice::Add): {
                std::cout << "******************** ADDING A NEW TODO **********************"
                          << std::endl;

                todoManger->addTodo();
                break;
            }
            case (Choice::Get): {
                std::cout << "******************** GET ALL TODOS **********************"
                          << std::endl;

                todoManger->getAllTodo();
                break;
            }
            case (Choice::Update): {
                std::cout << "******************** UPDATE EXISTING TODO **********************"
                          << std::endl;

                todoManger->updateTodo();
                break;
            }
            case (Choice::Delete): {
                std::cout << "******************** DELETE EXISTING TODO **********************"
                          << std::endl;

                todoManger->removeTodo();
                break;
            }
            case (Choice::Exit): {
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }
    return 0;
}