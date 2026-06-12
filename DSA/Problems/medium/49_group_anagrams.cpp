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
    * In this approach instead of using "0(n^2)" time complexity, we use "0(n * log n)" by sorting the "anagram"
    * Every similar anagrams will have same "word" after sorting it.
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

// More approach
/*
    * It's similar like previous one but instead of "o(n * log n)", we are doing within "O(n)" time complexity
*/
std::vector<std::vector<std::string>> findGroupedAnagrams(
    const std::vector<std::string>& anagrams) {
    if (anagrams.empty()) {
        return {};
    }

    std::unordered_map<std::string, std::vector<std::string>> commonAnagramsMap;

    for (const std::string& anagram : anagrams) {
        // ❌ Wrong thinking: You are thinking how to build a key, that's solution instead of directly loop through each char, We'll have to first count all the character than build the key.
        std::vector<int> charCounts(26, 0);

        for (const char& ch : anagram) {
            charCounts[ch - 'a']++;
        }

        // Build a unique key from frequencies, The '#' separator prevents
        // ambiguous key (e.g, counts [1, 2] vs [12] could collide without it).
        std::string frequencyKey = "";
        for (const int& count : charCounts) {
            frequencyKey += std::to_string(count) + "#";
        }

        // 👉 First time this key is seen:
        // 👉 C++ automatically does this behind the scenes.
        // 👉 commonAnagramsMap[frequencyKey] = vector<string> {}; // auto-creates (based on provided type)
        commonAnagramsMap[frequencyKey].push_back(anagram);  // then word is added.
    }

    // --> ⭐ Good comment not tell's about ("what the code does"), but ("explain about they") like used some special thing
    // Extract grouped value: Used "move" to avoid copying the inner vectors
    std::vector<std::vector<std::string>> anagramGroups;
    anagramGroups.reserve(commonAnagramsMap.size());

    for (auto& [_, anagrams] : commonAnagramsMap) {
        anagramGroups.push_back(std::move(anagrams));
    }

    return anagramGroups;
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