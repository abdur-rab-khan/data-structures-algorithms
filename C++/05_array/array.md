# 📃 Array

> It is a type of data structure which is used to store collection of same data type elements.

* There are two types of array.

    * Static Typed (Default).
    * Dynamic Typed (Vectors).

---

## 📔 Array Declaration
`type name_variable[size] = {element}`

So there two things that carry variable.
* Data.
* Size information.

```
int array[4] = {1,2,3,4};

cout << array <<endl; --> Return First Address.
cout << *array <<endl; --> Getting the value on first address.
```

> ***⚠️ Problem happen when we pass these array into the function. It only goes the first pointer address of the array instead of going all array.***

## 🍄‍🟫 Calling inside Function
```
void looping(int (&arr)[size_array]) // Reference to whole array

void looping(int arr[size]) // Same as int* array --> Lost size information and only has first pointer element.
```


## 🔁 Looping
```
// Using For Loop.
for(int i = 0; i < length; i++){
    cout << array[i] <<endl;
}

// While Loop.
while(length--){
    cout << array[length] <<endl;
}

// For Each.
for(int num : number){
    cout << num << endl;
}
```


## ⭐ Importent Methods for Array.



