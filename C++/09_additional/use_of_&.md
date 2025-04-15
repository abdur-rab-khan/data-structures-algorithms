# Use of **"&"** Symbole in Cpp.
> There are many use cased of & in C++. Using **`&`** can do many things like getting `Memory Address in Pointer`, `Reference Declaration`, `Pass by reference` , `Looping with Reference`, `Return Reference`.


## 0️⃣ Bitwise and Operator
```
int a = 6;    // 0110 in binary
int b = 3;    // 0011 in binary
int result = a & b;  // result = 2 (0010)
```
* Perform **`&`** operation on each bit.

## 1️⃣ Address of Operator
```
int a = 54;
int* ptr = &a;
```
* Here **`&a`** means "address of x".
* We get the address where `a` is stored.

## 2️⃣ Reference Declaration
```
int x = 55;
int& ref = a;
```
* Here **`int& ref`** means ref is alias to a.
* Any changes on **`ref`** can also effect on **`x`**.
* If is work as we add the ***original*** `x` variable on ref, not ***copy***.

## 3️⃣ Function Paramter: Pass by Reference
```
void reference_example(int &y)
{
    y = 500;
}

int y = 55;

cout << y << endl; // 55

reference_example(y);

cout << y << endl; // 500
```
* `int &y` means we pass ***original*** variable, not ***copy***
* Changes inside the function also effect on ***original*** variable.
* `const int &y` means you send as original variable, not ***copy***.
    * But `const` ensure that cannot modify the value.


## 4️⃣ Range-based For Loop with Reference
```
int nums[] = {1,2,3,4,5,6,7};

for(int &num : nums){
    num += 1
}
```
* `int &num` means you're referring to each original element.
* Without `&`, you'd work with a copy, and the original would not change.

## 5️⃣ Reference Return type
```
int& getElement(int (&arr)[4],int index){
    return arr[index];
}

int arr[5] = {11,22,33,44,55};

cout << arr[2] << endl; // 33

getElement(arr,2) = 303030;

cout << arr[2] << endl; // 303030
```
* It is modify because of getElement returns the `reference` that allow us to modify.
* `int& getElement` allow to return the original variable. that help to modify original one.

### 🧠 Pro Tips
---
* If you see **`&`** next to the type. it’s usually a reference.
* If you see **`&`** next to the variable. it’s likely the address-of operator.
