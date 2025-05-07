#include <map>
#include <string>

class Todo {
   private:
    map<int, std::string> todos;

   public:
    Todo() {}
    void addTodo(std::string todo);
    void updateTodo(int id, std::string updatedTodo);
    void removeTodo(int id);
    void getAllTodo();
};