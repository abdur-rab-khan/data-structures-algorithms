#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Brute force approach
bool isValidAnagram(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    std::vector<int> latterFrequencyCounter(26, 0);

    // Creating frequency count for str2 characters.
    for (const char& ch : str2) {
        latterFrequencyCounter[ch - 'a']++;
    }

    for (const char& ch : str1) {
        latterFrequencyCounter[ch - 'a']--;
    }

    for (const int& count : latterFrequencyCounter) {
        if (count != 0)
            return false;
    }

    return true;
}

std::vector<std::vector<std::string>> findGroupAnagrams(std::vector<std::string> anagrams) {
    std::vector<std::vector<std::string>> groupedAnagrams;

    int size = static_cast<int>(anagrams.size());

    for (int i = 0; i < size; i++) {
        std::string currentAnagram = anagrams[i];

        if (currentAnagram == "#PROCESSED#")
            continue;

        std::vector<std::string> currentAnagramsGroup;
        currentAnagramsGroup.push_back(currentAnagram);

        for (int j = i + 1; j < size; j++) {
            if (isValidAnagram(currentAnagram, anagrams[j])) {
                currentAnagramsGroup.push_back(anagrams[j]);
                anagrams[j] = "#PROCESSED#";
            }
        }

        groupedAnagrams.push_back(currentAnagramsGroup);
    }

    return groupedAnagrams;
}

// Optimized approach
/*
    * 
*/
std::vector<std::vector<std::string>> findAnagramsGroup(std::vector<std::string> anagrams) {
    std::unordered_map<std::string, std::vector<std::string>> sortedAnagramsMap;

    for (const std::string& anagram : anagrams) {
        std::string sortedAnagrams = anagram;
        std::sort(sortedAnagrams.begin(), sortedAnagrams.end());
        sortedAnagramsMap[sortedAnagrams].push_back(anagram);
    }

    std::vector<std::vector<std::string>> groupedAnagrams;
    for (auto& pair : sortedAnagramsMap) {
        // Instead of copying the pair, We directly move the ownership of pair
        // It's memory efficient, because we directly move the ownership where the pair is actually sorted.
        groupedAnagrams.push_back(std::move(pair.second));
    }

    return groupedAnagrams;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> groupedAnagram = findAnagramsGroup(strs);

    std::cout << "Grouped anagrams are: ";
    for (const std::vector<std::string>& groups : groupedAnagram) {
        std::cout << "[ ";
        for (const std::string& anagram : groups) {
            std::cout << anagram << ", ";
        }
        std::cout << " ], ";
    }

    return 0;
}