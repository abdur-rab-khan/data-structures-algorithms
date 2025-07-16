# String

> Strings are the sequence of characters, Unlike character array strings are ends with special character **\0**. \
> In most of the programming languages such as **Python**, **Java**, **Javascript** strings are immutable.

- [String](#string)
  - [Performing Some general Operation on String](#performing-some-general-operation-on-string)

- In C++, Strings can be defined as C-Style syntax using **"Character Array"** or using **"std::string"** class that are mutable internally represented as array. That provide different string manipulation methods.
  
  ```cpp
    #include <bits/stdc++.h>
    
    using namespace std;
    
    int main() {
        // Declaring String using C-Style.
        char myName[] = "Abdur Rab Khan";
    
        // Declaring String using std::string class.
        string my_name = "Abdur Rab Khan";
    
        printf("Using C-Style %s \n", myName);
    
        cout << "Using C++ Style " << my_name << "\n";
    
        return 0;
    }
  ```

    ![string-representation](https://media.geeksforgeeks.org/wp-content/uploads/20241206104942270669/String.png)

## Performing Some general Operation on String

1. **Length of string:** There is a build in function **`.size()`** that help to find size of the string which run on **o(1)** time complexity. Or we can use simple **while** loop to cout the size of string.
2. **Searching a Character:** Searching for a character means find the position where specific character appears. If character is present multiple times, we might have to return it first and last occurrence, or all occurrences.
  
    ```cpp
    // Give an character ch and string s. the task is found the index of first occurrence of the character ch. if not found return -1.  
    #include<bits/stdc++.h>
    
    int searchChar(std::string &s, char ch){
      for(int i = 0; i < s.size(); i++>){
        if(s[i] == ch){
          return i;
        }
      }

      return -1;
    }

    int main(){
      string name = "Abdur Rab Khan";
      char s1 = 'n';
      char s2 = 'l';

      cout << "Finding " << s1 << " in " << name << searchChar(name,s1); // 13
      cout << "Finding " << s2 << " in " << name << searchChar(name,s2); // -1

      return 0;
    }
    ```
