#include <iostream>
using namespace std;

int main()
{
    int a = 50, b = 50;

    int addition = a + b;       // 100
    int substraction = a - b;   // 0
    int multiplication = a * b; // 2500
    int divition = a / b;       // 1
    int modules = a % b;        // 0 --> Returns the division remainder

    // Increament Operator --> Inc by 1
    // In a_plus will be 50 because it is post increment mean it will first assign the value of a to a_plus and then increment the value of a by 1
    int a_plus = a++; // 50
    a_plus = a;       // 51

    // In pre increment it will first increment the value of a by 1 and then assign the value of a to a_plus
    int plus_a = ++a; // 52

    // Decrement Operator --> Dec by 1
    // In a_dec will be 50 because it is post decreament mean it will first assign the value of a to a_dec and then decrease the value of a by 1
    int a_dec = a--; // 52
    a_dec = a;       // 51

    // In pre Decreament it will first decrease the valur of a by 1 and then assign the value of a to dec_a
    int dec_a = --a; // 50
    return 0;
}