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
    void addTodo(std::string content) {
        id = generateRandomID();
        this->content = content;

        std::cout << ">>>>>>>>>> TODO IS ADDED SUCCESSFULLY <<<<<<<<<<<<<" << std::endl;
    }

    void getTodoProps() const {
        std::cout << "Content " << content << std::endl;
        std::cout << "Is Completed " << completed << std::endl << std::endl;
    }

    string getTodoContents() const { return content; }
};

class TodoManger {
   private:
    std::vector<Todo> todos;

    std::string getContentFromUser() {
        std::string content;
        std::cout << "Enter you todo content to add it. " << std::endl;
        std::getline(std::cin >> std::ws, content);

        if (content.length() == 1) {
            return NULL;
        }

        return content;
    }

   public:
    void addTodo() {
        std::string content = getContentFromUser();

        if (content != NULL) {
            Todo todo;
            todo.addTodo(content);

            todos.push_back(todo);
        } else {
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
        std::cout << "------------------ CHOOSE BETWEEN THEM ⬇️ -----------------" << std::endl;
        int choice;

        int counter = 1;
        for (const Todo& todo : todos) {
            std::cout << counter << ". " << todo.getTodoContents() << std::endl;
        }

        std::cout << "Enter you choice: ";

        if (choice > todos.size()) {
            std::cout << "⚠️ INVALID REQUEST OUT OF RANGE..." << std::endl;
        } else {
            std::string content;
            std::cout << "Enter you todo content to add it. " << std::endl;
            std::getline(std::cin >> std::ws, content);

            if (content.length() > 0) {
                Todo todo;
                todo.addTodo(content);

                todos.push_back(todo);
            }
        }
    }

    void removeTodo() {}
};

int main() {
    std::vector<Todo> todo;
    std::unique_ptr<TodoManger> todoManger = std::make_unique<TodoManger>();

    while (true) {
        int choice;
        std::cout << "1. To add new todo. \n 2. Update Todo. \n 3. Update existing todo. \n 4. "
                     "Delete todo."
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

                todoManger->getTodo();
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