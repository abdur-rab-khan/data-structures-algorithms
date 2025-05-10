#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <iostream>
#include <vector>

#include "Todo.hpp"

class TodoManager {
   private:
    std::vector<Todo> todos;

    std::string getContentFromUser();
    void printAllTodoContent();

   public:
    void addTodo();
    void getAllTodo();
    void updateTodo();
    void removeTodo();
};

#endif