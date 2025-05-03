# Exception Handling

> In C++, **exception** are unexpect error or problem occur while a program is running. For example, In a program that divides two numbers, try to dividing number by 0 is an exception as it may lead `undefined` error.

- The process of dealing with exception is **exception handing**. it allow us to make the program what ready for an error, and gracefully handle it.

- [Exception Handling](#exception-handling)
  - [**try catch block**](#try-catch-block)

## **try catch block**

>C++ provides build-in features for **exception handing** using **try** and **catch block**. it is an **exception handing** mechanism where the code that may cause exception is placed inside **try block** and the code that handles the exception is placed inside the **catch blokc**.
  
- **Example**

```cpp
try{
    // Code that might throw exception
}   catch(ExceptionType e){
    // exception handing code
} 
```

## **Throwing Exception**

> Throwing Exception means return some kind of value that represent exception from the **try block**. The matching catch block is found using the type of the throw value. The **throw** keyword is used to throw the exception.

- **Example**

  ```cpp
  try{
    throw val
  }
  catch(ExceptionType e){
    // exception Handling code
  }
  ```

- There are three type of values that can be thrown as an exception:
  1. Build-in Type
  2. Standard Exceptions
  3. Custom Exception

### Build-in Type

> Throwing build-in type is very simple but it does not provide any useful information

- **Example**

  ```cpp
  #include<iostream>
  using namespace std;

  int main(){
    int x = 7;

    try{
        if(x % 2 != 0){
            throw -1
        }
    }
    catch(int e){
        cout << "Exception Caught: " << e << endl;
    }

    return 0;
  }
  ```

  - **Output**

    ```shell
    Exception Caught: -1
    ```

### Throwing Standard Exceptions

> **Standard Exception** is a set of class representing different type of common exceptions. All these classes are define inside the \<stdexcept> header file and mainly derived from **std::exceptions** class this class is the base class for all exceptions. which is act as a base class for build in exceptions.

![standard-exceptions](https://media.geeksforgeeks.org/wp-content/uploads/20250411180615892273/cpp-exception-hierarchy.png)

- **Example**

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
    
  int main() {
    vector<int> v = {1, 2, 3};
    
    try {
        // Accessing out of bound element
        v.at(10);
    }
    catch (out_of_range e) {
        cout << "Caught: " << e.what();
    }
        return 0;
  }
  ```
  
  - The **what()** method is present in every standard exceptions to provide information about exception in self, with these exceptions.

  - **Output**

    ```shell
    Caught: vector::_M_range_check: __n (which is 10) >= this->size() (which is 3)
    ```

## Throwing custom exceptions

> When standard exception is cannot satisfy our requirements, we can create a custom exception class. It is recommended to inherit standard exception class in the class seamless integrity with library components though, it is not compulsory.

- **Example**
  - **Creating a custom exception class**

    > We can create custom exception class in case the provided exception does not meet our requirements.

    1. **Inheriting from std::exception**

        ```cpp
        #include <iostream>
        using namespace std;
        
        class CustomException : public exception {
        public:
            const char* what() const noexcept override { return "This is custom exception"; }
        };
        
        int main() {
            try {
                // Throwing our custom exception
                throw CustomException();
            } catch (CustomException e) {
                cout << "Caught an Exception " << e.what() << endl;
            }
        
            return 0;
        }
        ```

        - **Output**

            ```shell
            Caught an Exception: This is custom exception
            ```

    2. **Inheriting other exceptions**

        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        
        class CustomExcept : public runtime_error {
        public:
        
            // Using constructor for passing custom message
            CustomExcept(const string& message)
                : runtime_error(message) {}
        };
        
        int main() {
            try {
                throw CustomExcept(
                    "This is a custom runtime_exception!"
                );
            }
            catch (const CustomExcept& e) {
                cout << e.what();
            }
            return 0;
        }
        ```

    3. **Creating Non-Standard Exception**

       ```cpp
       #include <bits/stdc++.h>
        using namespace std;
        
        class CustomExcept {
        public:
            CustomExcept(const string& msg) : message(msg) {}
            
            // Handle custom exception using
            // what() method.
            const char* what() const {
                return message.c_str();
            }
        
        private:
            string message;
        };
        
        int main() {
            try {
                throw CustomExcept(
                    "This is a custom exception!"
                );
            }
            catch (const CustomExcept& e) {
                cout << e.what();
            }
            return 0;
        }
       ```

  - Passing a custom message

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        int num = 10;
        int den = 0;
        int res;
        
        // Checking division by zero
        try {
            if (!den) {
                
                // Passing custom message
                throw runtime_error("Division by Zero");
            }
            res = num/den;
        }
        catch (const runtime_error& e) {
            cout << "Caught: " << e.what();
        }
    
        return 0;
    }
    ```

## Caching Multiple Exceptions

> There can be multiple catch block associated with single try block to handle multiple types of exceptions.

- **Example**

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
    
    // Code that might throw an exception
    try {
        int choice;
        cout << "Enter 1 for invalid argument, "
            << "2 for out of range: ";
        cin >> choice;

        if (choice == 1) {
            throw invalid_argument("Invalid argument");
        }
        else if (choice == 2) {
            throw out_of_range("Out of range");
        }
        else {
            throw "Unknown error";
        }

    }
    
    // executed when exception is of type invalid_argument
    catch (invalid_argument e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // executed when exception is of type out_of_range
    catch (out_of_range e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // executed when no matching catch is found
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
    }
    ```

## Catch by Reference or Value

> The catch block can catch exception either by **value** or **reference**. Both of the methods have their own advantages.

### Catch by value

> Catching exception by value creates new copy of throw exception object in the catch block. Generally, the exceptions objects are not very large so there is not much overhead of creating copies.

- **Example**

  ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        try {
            throw runtime_error("This is runtime exception");
        }
        
        // Catching by value
        catch (runtime_error e) {
            cout << "Caught: " << e.what();
        }
    
        return 0;
    }
  ```

### Catch by reference

> Catch by reference method just pass the reference to the exception thrown instead of creating a copy. Although it reduces the copy overhead, it is not the primary advantage of this method. The main advantage of this method is in catching polymorphic exception types.

- **Example**

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        try {
            throw runtime_error("This is runtime exception");
        }
        
        // Catching by value
        catch (exception& e) {
            cout << "Caught: " << e.what();
        }
    
        return 0;
    }
    ```
