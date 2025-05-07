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
    Delete = 4,
    Update = 3,
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
    Todo() {
        this->id = generateRandomID();

        std::cout << "Enter todo ";
        std::getline(std::cin >> std::ws, this->content);
    }

    void getTodo() const {
        std::cout << "Content " << content << std::endl;
        std::cout << "Is Completed " << completed << std::endl;
    }
};

class TodoManger {
   private:
    std::vector<Todo> todos;

   public:
    void addTodo(Todo todo) {
        todos.push_back(todo);
        std::cout << "Todo is added successfully" << std::endl;
    }

    void getTodo() {
        std::cout << "------------------ LIST OF TODOS -----------------" << std::endl;
        for (const Todo& todo : todos) {
            todo.getTodo();
        }
    }
};

int main() {
    std::vector<Todo> todo;
    std::unique_ptr<TodoManger> todoManger = std::make_unique<TodoManger>();

    while (true) {
        int choice;
        std::cout << "Enter you choice: ";
        std::cin >> choice;
        Choice userChoice = static_cast<Choice>(choice);

        switch (userChoice) {
            case (Choice::Add): {
                std::cout << "---------------- ADDING A NEW TODO ------------------" << std::endl;
                Todo todo;

                todoManger->addTodo(todo);
                break;
            }
            case (Choice::Get): {
                std::cout << "--------------------- GET TODO -------------------" << std::endl;

                todoManger->getTodo();
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