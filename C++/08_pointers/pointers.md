# 🪞 Reference
> The `reference` is the alias of another variable. It is not a copy but another name for existing one.
* ***For more refer from additional folder.***

## 🧑🏻‍💻 Example
```
int num = 55;
int& ref = num;

cout << ref <<endl; // 55
cout << num << endl; // 55

ref = 66;

cout << ref <<endl; // 66
cout << num <<endl; // 66
```
* `ref` refer to `num`.
* Changes on `ref` can also effect to `num` and `vise-versa`.



# 💽 Pointer
> The `Pointer` is used to get the memory address of the given variable. To get memory address we use **`&`** Operator.

* In C++, When we create variable a memory address is assigned to the variable. And when assign value to the variable, it stored in the memory address.
* A **`pointer`** is a variable that store the memory address as its value. We can't store memory address directly.
* A **`pointer`** variable points to a data type (like `int`, `string`) of the same type. and is created using **`*`** operator.
## 🧑🏻‍💻 Example
```
int num = 11;

cout << &num <<endl; // We get memory address


int x = 55;
int* ptr = &x;

cout << x <<endl; // Memory address of variable x.
```