#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class WithoutSmartPtr {
   public:
    int** marks = nullptr;
    int total_student = 0;
    int total_subject = 5;

    WithoutSmartPtr(int total_student) {
        cout << "Without using Smart Pointer" << endl << endl;
        ;
        this->total_student = total_student;
        marks = new int*[total_student];
    }

    void add_marks() {
        int mark = 0;

        for (int i = 0; i < total_student; i++) {
            marks[i] = new int[total_subject];
            cout << "Enter Student " << i + 1 << " marks " << endl;

            for (int j = 0; j < total_subject; j++) {
                cout << "Enter you marks:- ";
                cin >> mark;

                marks[i][j] = mark;
            }
        }
    }

    void display_marks() {
        for (int i = 0; i < total_student; i++) {
            cout << "Student " << i + 1 << " marks:- ";

            for (int j = 0; j < total_subject; j++) {
                cout << marks[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~WithoutSmartPtr() {
        for (int i = 0; i < total_student; i++) {
            delete[] marks[i];
        }

        delete[] marks;
    }
};

class WithSmartPtr {
   public:
    vector<vector<int>> marks;
    int total_student = 0;
    int total_subject = 5;

    WithSmartPtr(int total_student) {
        cout << "With using Smart Pointer" << endl << endl;
        this->total_student = total_student;
        marks.resize(total_student, vector<int>(total_subject));
    }

    void add_marks() {
        for (int i = 0; i < total_student; i++) {
            cout << "Enter Student " << i + 1 << " marks " << endl;

            for (int j = 0; j < total_subject; j++) {
                cout << "Enter you marks:- ";
                cin >> marks[i][j];
            }
        }
    }

    void display_marks() {
        for (int i = 0; i < total_student; i++) {
            cout << "Student " << i + 1 << " marks:- ";

            for (int j = 0; j < total_subject; j++) {
                cout << marks[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    // Building a small system that stores the marks of students. The number of students is not
    // fixed — it is decided at runtime.

    // Without Smart Pointer
    WithoutSmartPtr wsp = WithoutSmartPtr(2);
    wsp.add_marks();
    wsp.display_marks();

    // With Smart Pointer
    WithSmartPtr spt = WithSmartPtr(2);
    spt.add_marks();
    spt.display_marks();
    return 0;
}