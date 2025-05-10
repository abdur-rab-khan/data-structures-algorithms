#pragma once

#include <string>

class Todo {
   private:
    std::string content;
    bool isCompleted = false;

   public:
    Todo(const std::string& content);

    // Member functions
    std::string getContent() const;
    void getTodoProps() const;
    void updateTodo(const std::string& content = "", bool isCompleted = false);
};