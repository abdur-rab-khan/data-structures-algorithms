#include <cstring>
#include <iostream>
using namespace std;

class Book {
    char* title = nullptr;
    int page;

   public:
    Book(const char* title, int page) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->page = page;
    }

    void showBookInfo() {
        cout << "Title is " << title << endl;
        cout << "Page Number is " << page << endl;
    }

    // copy constructor (for deep copy)

    ~Book() { delete[] title; }
};

int main() {
    Book b1("C++ foundation", 53);

    b1.showBookInfo();
    return 0;
}