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
2. [**Searching a Character:**](./problems/easy/others/01_searchChar.cpp) Searching for a character means find the position where specific character appears. If character is present multiple times, we might have to return it first and last occurrence, or all occurrences.
  
    ```cpp
    // Give an character ch and string s. the task is found the index of first occurrence of the character ch. if not found return -1.  
    #include <bits/stdc++.h>
    
    int searchChar(std::string s, char ch) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) {
                return i;
            }
        }
    
        return -1;
    }
    
    // Using in-build function
    int searchCharS(std::string s, char ch) {
        size_t idx = s.find(ch);
    
        // When these functions ('find', 'rfind', 'find_last_of', 'find_first_of') not found return
        // std::string:npos
        if (idx != std::string::npos) {
            return idx;
        }
    
        return -1;
    }
    
    int main() {
        std::string name = "Abdur Rab Khan";
        char s1 = 'l';
        char s2 = 'n';
    
        std::cout << "Finding " << s1 << " in name " << searchChar(name, s1) << "\n";
        std::cout << "Finding " << s2 << " in name " << searchChar(name, s2) << "\n";
    
        std::cout << "<==========> Second Method <============>" << "\n";
        std::cout << "Finding " << s1 << " in name " << searchCharS(name, s1) << "\n";
        std::cout << "Finding " << s2 << " in name " << searchCharS(name, s2) << "\n";
    
        return 0;
    }
    ```

3. **Check for Substring:** Check for sub-string means, finding small sequence of character within large string.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // Approach 1 o(m * n)
    int checkSubstring(string txt, string pt) {
        int n = txt.size();
        int m = pt.size();
    
        // Instead of running till n we can substact with m, We know that at every index we already
        // check i + m, So no need to run till n;
        for (int i = 0; i <= n - m; i++) {
            // Check for substring match
            int j;
            for (j = 0; j < m; j++) {
                // If miss match
                if (txt[i + j] != pt[j]) {
                    break;
                }
            }
    
            // j == m  which means that, j is running til pt.length without any break means pt is the
            // substring of txt.
            if (j == m) {
                return i;
            }
        }
    
        return -1;
    }
    
    // Using build-in method
    int checkSubString(string txt, string pt) {
        int idx = txt.find(pt);
    
        if (idx != string::npos) {
            return idx;
        }
    
        return -1;
    }
    
    int main() {
        // Task: Given a two string txt and pt, the task is to find if pat is a substring of txt. If yes
        // return index of first occurrence otherwise return -1.
        string txt = "Abdur Khan Rab Khan";
        string pt = "Khan";
    
        cout << "Check " << pt << " is substring of " << txt << " : " << checkSubstring(txt, pt)
            << "\n";
        cout << "Check " << pt << " is substring of " << txt << " : " << checkSubString(txt, pt)
            << "\n";
        return 0;
    }
    ```

4. [**Insert a Character:**](./problems/easy/others/03_insert_char.cpp) Inserting a Character means adding **"char"** at any specific position while maintaining the order of original order of string.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // approach 1 o(s.length);
    string insertString(string s, char ch, int pos) {
        string res = "";
    
        for (int i = 0; i < s.length(); i++) {
            // Insert character at given pos
            if (i == pos - 1)
                res.push_back(ch);
    
            res.push_back(s[i]);
        }
    
        return res;
    }
    
    // approach 2
    string insertStringS(string& s, char ch, int pos) {
        // Insert char at give pos
        s.insert(s.begin() + pos, ch);
        return s;
    }
    
    int main() {
        // Task: Given an string s, character ch and integer pos, So the task is to add "ch" in "s" at
        // "pos" and return updated string.
        string greet = "ABDE";
        char s = 'c';
    
        cout << insertString(greet, s, 3) << endl;
        cout << insertStringS(greet, s, 3) << endl;
    
        return 0;
    }
    ```

5. [**Delete Char in String:**](./problems/easy/others/04_del_char_string.cpp) Delete Char in String means remove character **"ch"** from given string s.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    string deleteString(string s, char ch) {
        string res = "";
    
        for (const char c : s) {
            if (c != ch) {
                res += c;
            }
        }
    
        return res;
    }
    
    int main() {
        // Task: Given an string s and char ch, Task is to remove character from given s.
        string greet = "Hello world!";
        char ch = '!';
    
        cout << deleteString(greet, ch);
        return 0;
    }
    ```

6. [**Left Rotation of a string:**](./problems/easy/others/05_left_rotation_string.cpp) Left Rotation of a string means that transformation of a string where character from the beginning of the string are moved to the end of the string, maintaing there relative order. The number of character moved determines the **"amount"** of the rotation.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    void reverseStr(string& s, int start, int end) {
        // Loop from both size till middle point
        while (start < end) {
            int temp = s[start];
            s[start] = s[end];
            s[end] = temp;
    
            start++;
            end--;
        }
    }
    
    // Native approach time complexity n(n * k), space complexity o(1)
    void leftRotation(string& s, int k) {
        int n = s.size();
    
        for (int i = 0; i < k; i++) {
            int first = s[0];
    
            for (int j = 0; j < n; j++)
                s[j] = s[j + 1];
    
            s[n - 1] = first;
        }
    }
    
    // approach 1 time complexity worst case o(n²) = o(n), space complexity o(n)
    string leftRotationSecond(string s, int k) {
        string updated = "";
    
        for (int i = k; i < s.size(); i++) {
            updated.push_back(s[i]);
        }
    
        for (int i = 0; i < k; i++) {
            updated.push_back(s[i]);
        }
    
        return updated;
    }
    
    void leftRotationUsingRev(string& s, int k) {
        int n = s.size();
    
        // Performing reverse ==> example s = abcdefg
        // Reverse s[0, k - 1] ==> abc ==> cba ==> cbadefg
        reverseStr(s, 0, k - 1);
    
        // Reverse s[2, n - 1] ==> defg ==> gfed ==> cbagfed
        reverseStr(s, k, n - 1);
    
        // Reverse s[0, n - 1] ==> defgabc
        reverseStr(s, 0, n - 1);
    }

    int main() {
        string s = "GeeksforGeeks";
        string a = "ABCdefg";
        int d = 2;
    
        leftRotation(s, d);
        leftRotation(a, 3);
    
        cout << s << endl;
        cout << a << endl;
    
        s = "GeeksforGeeks";
        a = "ABCdefg";
    
        leftRotationUsingRev(s, d);
        leftRotationUsingRev(a, 3);
    
        cout << s << endl;
        cout << a << endl;
    
        return 0;
    }
    ```
