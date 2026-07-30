#include "../includes/Todo.hpp"

#include <iostream>

Todo::Todo(const std::string& content) {
    this->content = content;
};

std::string Todo::getContent() const {
    return content;
}

void Todo::getTodoProps() const {
    std::cout << "Content: " << content << "\nIs Completed: " << isCompleted << "\n\n";
}

void Todo::updateTodo(const std::string& content, bool isCompleted) {
    if (!content.empty())
        this->content = content;

    if (this->isCompleted != isCompleted)
        this->isCompleted = isCompleted;
}
