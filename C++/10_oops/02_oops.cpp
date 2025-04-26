#include <iostream>
using namespace std;

class A {
   protected:
    string password;

   public:
    void setPassword(string pass) { password = pass; }
};

class B : public A {
    string name = "Abdur Rab Khan";
    int age = 21;

   public:
    bool isCorrectPass() {
        string pass;
        cout << "Enter pass ";
        getline(cin, pass);

        return password == pass;
    }

    void printMyInfo() {
        bool isCorrect = isCorrectPass();

        if (isCorrect) {
            cout << "Name " << name << endl;
            cout << "Age " << age << endl;
        } else {
            cout << "Password is incorrect" << endl;
        }
    }
};

int main() {
    B p1;

    p1.setPassword("abdurrab123");

    // cout << p1.password; ⚠️ We can't access it.

    p1.printMyInfo();
    return 0;
}