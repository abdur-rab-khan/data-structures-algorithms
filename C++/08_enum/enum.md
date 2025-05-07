# 📑 Enumeration (Enum)
>
> `Enum` is a special type that represent the group of constants (unchangeable value).

* There are many two types of `enum`.
  * Default `enum`
  * `enum class`

## 🖊️ **`enum`** Declaration

```cpp
enum Gender{
    MALE,
    FEMALE
}
```

* `Gender` is the name of the enum type.
* `MALE`, `FEMALE` are named constants.
* By default, `MALE` has value 0, `FEMALE` has value 1.

* But we can also define value on them.

```cpp
enum Gender{
    MALE = 5,
    FEMALE = 6
}
```

## 🏛️ **`enum class`** Declaration

```cpp
enum class HTTPStatus{
    Ok = 200,
    NotFound = 404,
    InteralError = 500
}
```

## ➕ Implementation

* ### `enum`

```cpp
enum HTTPStatus{
    Ok = 200,
    NotFound = 404,
    InteralError = 500
}

int main(){
    HTTPSStatus status = Ok;

    if(status == Ok){
        cout << "Request is successful << endl;
    }else if(status == NotFound){
        cout << "NotFound <<endl;
    }else{
        cout << "Interal Error <<endl;
    }

    return 0;
}
```

* ### `enum class`

```cpp
enum class HTTPStatus{
    Ok = 200,
    NotFound = 404,
    InternalError = 500
}

int main(){
    HTTPStatus status = HTTPStatus::Ok;
    int code = static_cast<int>(status); // Explicaity convert to int.

    switch (status)
    {
    case HTTPStatus::Ok:
        cout << "Request successful." << endl;
        break;
    case HTTPStatus::NotFound:
        cout << "Not Found." << endl;
        break;
    case HTTPStatus::InteralError:
        cout << "Interal Error happen." << endl;
        break;
    }

    return 0;
}
```

## 🔑 Key Difference between `enum` and `enum class`

| Feature | `enum` | `enum class` |
| --- | --- | --- |
| Scope | Global scope - enum values are placed in the enclosing scope | Scoped within the enum - must be accessed using enum name |
| Type Safety | Weak - can be implicitly converted to integers and mixed with other enums | Strong - no implicit conversion, must use explicit casting |
| Default Underlying Type | `int` by default | Can be explicitly specified (e.g. `enum class Colors : uint8_t`) |
| Access | Direct access to enum values (e.g. `RED`) | Must use scope resolution (e.g. `Colors::RED`) |
| Size | Usually 4 bytes (size of int) | Can be optimized by specifying underlying type |

## ⚒️ Use Cases

* `Enum` is most commonly use in large application, for type safety and naming convention.
* It is also used in `switch` statement to make code more readable.
* `Enum` is also used in `API` to define the status code, error code, etc.
* It is also used in `game development` to define the state of the game, player, etc.
