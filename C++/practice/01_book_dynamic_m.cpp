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

    // copy constructor (for deep copy)
    Book(const Book& obj) {
        this->page = obj.page;
        int size = strlen(obj.title);
        title = new char[size];
        strcpy(title, obj.title);
    }

    void showBookInfo() {
        cout << "Title is " << title << endl;
        cout << "Page Number is " << page << endl;
    }

    void setTitle(const char* newTitle) {
        delete[] title;
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
    }

    ~Book() { delete[] title; }
};

int main() {
    Book b1("C++ foundation", 53);
    Book b2(b1);

    cout << "Before Changing " << endl << endl;

    b1.showBookInfo();
    b2.showBookInfo();

    cout << endl << "After changing " << endl << endl;
    b1.setTitle("Rust Foundation");

    b1.showBookInfo();
    b2.showBookInfo();

    /*
    Before using Copy Constructor OutPut is:

    Before Changing

    Title is C++ foundation
    Page Number is 53
    Title is Rust Foundation
    Page Number is 53

    After changing

    Title is Rust Foundation
    Page Number is 53
    Title is Rust Foundation
    Page Number is 53
    */

    /*
    After using Copy Constructor Output is:

    Before Changing

    Title is C++ foundation
    Page Number is 53
    Title is C++ foundation
    Page Number is 53

    After changing

    Title is Rust Foundation
    Page Number is 53
    Title is C++ foundation
    Page Number is 53
    */
    return 0;
}