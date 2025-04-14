#include <iostream>
using namespace std;

int main()
{
    string guess_name;
    int guess_age;

    string name = "Abdur Rab Khan";
    int age = 21;

    cout << "Guess my name and age" << endl;
    cout << "Enter my name:- ";
    // cin >> guess_name; --> When we enter "Abdur Rab Khan" --> it only reads "Abdur". beacuse of space between them. Other "Rab", "Khan" will remaining into the buffer. when they go to add guess_age causing error that is the reason why directly jump into IF_ELSE block without asking about guess_age.
    getline(cin, guess_name); // Read entire line including spaces.

    cout
        << "Enter my age:- ";
    cin >> guess_age;

    cout << guess_name << endl
         << guess_age << endl;

    // IF block is True then it the block of code inside it, and does not run ELSE block.
    // ELSE block only run if, IF block code False.
    // if (guess_name == name && guess_age == age)
    // {
    //     cout << endl
    //          << "Correct that is my name and age." << endl;
    // }
    // else
    // {
    //     cout << endl
    //          << "That's not my name and age." << endl;
    // }

    if (guess_name != name || guess_age != age)
    {
        if (guess_age != age && guess_name != name)
        {
            cout << guess_name << ", " << guess_age << " Both are incorrect." << endl;
        }
        else if (guess_name != name)
        {
            cout << guess_name << " It's not my name." << endl;
        }
        else if (guess_age != age)
        {
            cout << guess_age << " It's not my age." << endl;
        }
    }
    else
    {
        cout << endl
             << "That's my name and age.";
    }
    return 0;
}