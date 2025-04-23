#include <iostream>
#include <tuple>
#include <utility>
using namespace std;

string getAge(int age = 0);

string getAge(int age) {
    return "Your age is " + to_string(age);
}

inline int sqrt(int x) {
    return x * x;
}

// Return multiple return from function
// Using pair
pair<string, int> add(int a, int b) {
    return make_pair("Sum:- ", a + b);
}

tuple<string, int, string, int, string, int> math(int a, int b) {
    return make_tuple("Sum:- ", a + b, "Difference:- ", a - b, "Multi:- ", a * b);
}

int main() {
    cout << getAge() << endl;
    cout << getAge(21) << endl;

    cout << sqrt(2) << endl;

    int num = 55;
    // Lambda function --> variable by value
    auto numSqrt = [=](int x) {
        x = x * x;
        return x;
    };

    cout << "Original:- " << num << endl;
    cout << "Num Sqrt:- " << numSqrt(num) << endl << endl;

    // Lambda function --> variable by reference
    auto numSqrt2 = [=]() {
        int x = num * num;
        return x;
    };

    cout << "Original:- " << num << endl;
    cout << "Num Sqrt:- " << numSqrt2() << endl;

    // Return Multiple Value
    pair<string, int> addition = add(5, 10);

    cout << addition.first << addition.second << endl;

    tuple<string, int, string, int, string, int> calculatedValue = math(10, 10);

    cout << get<0>(calculatedValue) << get<1>(calculatedValue) << endl;
    cout << get<2>(calculatedValue) << get<3>(calculatedValue) << endl;
    cout << get<4>(calculatedValue) << get<5>(calculatedValue) << endl;
    return 0;
