#include <iostream>
using namespace std;

// struct
// {
//     string name;
//     string model;
//     int year;
//     bool is_electric;

//     void display()
//     {
//         cout << model << endl
//              << year << endl
//              << is_electric << endl;
//     }
// } c1;

struct Car
{
    string name;
    string model;
    int year;
    bool is_electric;

    // We can also add constructor in the struct
    Car(string name, string model, int year, bool is_electric)
    {
        this->name = name;
        this->model = model;
        this->year = year;
        this->is_electric = is_electric;
    }

    void display()
    {
        cout << "Name of the Car is:- " << name << endl;
        cout << "Model of the Car is:- " << model << endl;
        cout << "Year of the Car is:- " << year << endl;
        cout << "Is Car Electric:- " << is_electric << endl;
    }
};

int main()
{
    // c1.name = "Tesla";
    // c1.model = "S1";
    // c1.year = 2022;
    // c1.is_electric = true;
    Car c1("Tesla", "S1", 2023, true);

    c1.display();

    return 0;
}