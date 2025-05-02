#include <cstring>
#include <iostream>

using namespace std;

class String {
    char* str;

   public:
    // Constructor
    String(const char* s = NULL);

    // Destructor to clean it.
    ~String() { delete[] str; }

    // Copy Constructor
    String(const String&);

    // Print method
    void print() { cout << str << endl; }

    // Change value
    void change(const char*);
};

String::String(const char* s) {
    int size = strlen(s) + 1;

    str = new char[size];
    strcpy(str, s);
}

String::String(const String& old_str) {
    int size = strlen(old_str.str);

    str = new char[size + 1];
    strcpy(str, old_str.str);
}

void String::change(const char* s) {
    delete[] str;

    int size = strlen(s) + 1;
    str = new char[size];
    strcpy(str, s);
}

int main() {
    String str1("Abdur Rab");

    String str2 = str1;

    str2.print();
    str1.print();

    str2.change("Abdur Rab Khan");

    str1.print();
    str2.print();

    return 0;
}