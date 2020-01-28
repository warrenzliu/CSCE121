
#include <iostream>
#include <string>
#include <cctype>
#include "Functions.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    //These two bool values are used later to check for flags
    bool flagCase = false;
    bool flagSpace = false;
    //Have a hyphen count to make sure I know where the words start
    int hyphenCount = 1;
    //loop through argc to find if there are any flags
    for (int i = 1; i < argc; i++){
        string insideArgv = argv[i];
        insideArgv = toLower(insideArgv);
        for (int k = 0; k < insideArgv.size(); k++){
            if (insideArgv.at(k) == 's')
                flagSpace = true;
            if (insideArgv.at(k) == 'c')
                flagCase = true;
            if (insideArgv.at(k) == '-')
                hyphenCount += 1;
        }
    }
    //random variable to place into the function printUsageInfo
    string random = argv[0];
    //This just checks if argc doesn't have words
    if (argc == hyphenCount){
        printUsageInfo(random);
    }
    else{
        int i = hyphenCount;
        while (i<argc){
            string input = argv[i];
            //checks for numbers or letters at the beginning
            if (isalpha(input.at(0)) || isdigit(input.at(0))){
                input = removePunctuation(input,true);
                if (isPalindrome(input,flagCase,flagSpace))
                    cout << "\"" << input << "\"" << " is a palindrome." << endl;
                else
                    cout << "\"" << input << "\"" << " is not a palindrome." << endl;
                i+=1;
            }
            //Checks for the quotation mark and if there is one, adds the next word to the current word
            else if(ispunct(input.at(0))){
                input += argv[i+1];
                input = removePunctuation(input,true);
                if (isPalindrome(input,flagCase,flagSpace))
                    cout << "\"" << input << "\"" << " is a palindrome." << endl;
                else
                    cout << "\"" << input << "\"" << " is not a palindrome." << endl;
                //need to iterate over 2 because I added the next word (i+1) to the current word
                i+=2;
            }
            
        }
    }
}
