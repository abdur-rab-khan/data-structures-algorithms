#include <iostream>
#include <vector>

using namespace std;

struct CustomInt {
    int value;
    // explicit constexpr CustomInt(const int value) : value(value) {}

    // Todo: [it's wrong] "noexpect" with function means, It should not have any "throw error" within the function otherwise, It won't compile and throw error in compile time.
    constexpr CustomInt(const int val) noexcept {
        if (val <= 0) {
            value = -1;
            // throw overflow_error("You can't give me less than zero baby!!");
        } else {
            value = val;
        }
    }

    // constexpr CustomInt operator*(const CustomInt& secondNum) const {
    //     return (this->value * secondNum.value) + 10;
    // }
};

// Because I've overloaded the "*" operator, Compiler running the following expression instead of default having an error (We can't multiply to object).
CustomInt operator*(const CustomInt& firstNumber, const CustomInt& secondNumber) {
    return CustomInt {(firstNumber.value * secondNumber.value) + 1};
}

int main() {
    CustomInt firstInt {5};
    CustomInt secondInt {10};

    cout << "The multiplication of firstInt * secondInt is: " << (secondInt * firstInt) << endl;

    return 0;
}