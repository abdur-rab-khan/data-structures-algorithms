#include <bits/stdc++.h>
using namespace std;

bool isAdult(int age) {
    if (age >= 18) {
        return true;
    } else {
        return false;
    }
}

bool isTeenager(int age) {
    return age >= 13 && age < 18;
}

int main() {
    int age = 20;

    if(isAdult(age)){
        cout << "You are an adult." << endl;
    }else if(isTeenager(age)){
        cout << "You are a teenager." << endl;
    }else{
        cout << "You are a child." << endl;
    }

    return 0;
}