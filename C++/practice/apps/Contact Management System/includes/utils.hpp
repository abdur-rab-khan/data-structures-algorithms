#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <regex>
#include <string>

bool isValid(std::string content, std::regex match_regex);

std::string trim(const std::string& s);

std::string getHeadingMessage(std::string msg);

int getChoice(int max = 0);

std::string getStringFromUser(std::string msg, bool strict = true);

std::string getPhoneNumberFromUser(std::string msg = "Enter a phone number: ", bool strict = true);

std::string getEmailFromUser(std::string msg = "Enter a email address: ", bool strict = true);

std::string getWebsiteFromUser(std::string msg = "Enter a website uri: ", bool strict = true);

#endif