#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
#include <string>
void printUsageInfo(std::string name);
bool isPalindrome(std::string input, bool flagCase, bool flagSpace);
std::string toLower(std::string input);
std::string removePunctuation(std::string input, bool flagSpace = false);
#endif
