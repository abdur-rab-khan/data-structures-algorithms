#include<iostream>


int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i + 2) {
        std::cout << "Hello is: " << argv[i] << std::endl;
    }

    return 0;
}
