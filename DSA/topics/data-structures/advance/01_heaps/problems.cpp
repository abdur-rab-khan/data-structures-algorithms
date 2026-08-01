#include <iostream>
#include <vector>

#include "../../../../dsa_utils.h"

using namespace std;

namespace Problems {
    namespace EasyProblems {
        void main() {
            cout << "Easy Problems: " << endl << endl;

            cout << endl;
        }
    }  // namespace EasyProblems

    namespace MediumProblems {
        void main() {
            cout << "Medium Problems: " << endl << endl;

            cout << endl;
        }
    }  // namespace MediumProblems

    namespace HardProblems {
        void main() {
            cout << "Hard Problems: " << endl << endl;
        }
    }  // namespace HardProblems

    void main() {
        EasyProblems::main();
        MediumProblems::main();
        HardProblems::main();
    }
};  // namespace Problems

int main() {
    Problems::main();
    return 0;
}
