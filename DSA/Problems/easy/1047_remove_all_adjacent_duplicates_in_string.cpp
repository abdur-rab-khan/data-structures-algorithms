#include <bits/stdc++.h>
using namespace std;

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

int main() {
    std::string str1 = "abbaca";
    std::string str2 = "azxxzy";

    std::cout << "Removed adjacent string is: " << removeAllAdjacent(str1) << std::endl;
    std::cout << "Removed adjacent string is: " << removeAllAdjacent(str2) << std::endl;
    
    return 0;
}