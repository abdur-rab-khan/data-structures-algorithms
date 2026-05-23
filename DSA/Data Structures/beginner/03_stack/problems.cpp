#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>



namespace easy{
    bool isValidParenthesis(std::string str) {
        // Checking parenthesis is valid or not.
        std::stack<char> st;

        for (const char& ch : str) {
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else{
                if(st.empty())
                    return false;

                char top = st.top();
                st.pop();
                if(ch == ')' && top != '(') return false;
                if(ch == ']' && top != '[') return false;
                if(ch == '}' && top != '{') return false;
            }
        }

        return st.empty();
    }

    // 1047_remove_all_adjacent_duplicates_in_string
    std::string removeAllAdjacent(std::string str){
        std::string uniqueStr;

        for(const char& ch: str){
            if(!uniqueStr.empty()){
                char top = uniqueStr.back();

                if(ch == top){
                    uniqueStr.pop_back();
                }else {
                    uniqueStr.push_back(ch);
                }
            } else {
                uniqueStr.push_back(ch);
            }
        }

        return uniqueStr;
    }

    void main() {
        // Question 1.
        std::string str1 = "()";
        std::string str2 = "(]";
        std::string str3 = "()[]{}";
        std::string str4 = "([{}])";

        std::cout << "Is Valid Parenthesis: " << str1 << (isValidParenthesis(str1) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str2 << (isValidParenthesis(str2) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str3 << (isValidParenthesis(str3) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str4 << (isValidParenthesis(str4) ? " true" : " false") << std::endl;

        // Question 2.
        std::string str1 = "abbaca";
        std::string str2 = "azxxzy";

        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str1) << std::endl;
        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str2) << std::endl;
    }
};  // namespace easy

int main() {
    easy::main();

    return 0;
}