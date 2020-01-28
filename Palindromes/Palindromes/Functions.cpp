#include "Functions.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
//uses the tolower function to lower every letter of the string "input"
string toLower(string input){
    for (int i = 0; i<input.size();++i){
        input.at(i)=tolower(input.at(i));
    }
    return input;
}
//removes punctuations by using the ispunct function and then removes spaces if flagSpace is false
string removePunctuation(string input, bool flagSpace){
    for (int i = 0; i<input.size();++i){
        if (ispunct(input.at(i))){
            input = input.substr(0,i)+input.substr(i+1,input.size()-1);
        }
    }
    if (flagSpace == false){
        for (int i = 0; i<input.size();++i){
            if (isspace(input.at(i))){
                input = input.substr(0,i)+input.substr(i+1,input.size()-1);
            }
        }
    }
    return input;
}
//prints usage info
void printUsageInfo(string name){
    cout << "Usage: ./palindrome [-c] [-s] string ..." <<endl;
    cout << "-c: case sensitivity turned on" << endl;
    cout <<  "-s: ignoring spaces turned off" <<endl;
}

bool isPalindrome(string input, bool flagCase, bool flagSpace){
    //
    bool palindrome = true;
    //base case
    if (input.size() <= 2){
        //checks through the different flag cases
        if (flagCase==false && flagSpace==false){
            input = toLower(input);
            input = removePunctuation(input, flagSpace);
            
        }
        else if (flagCase == true && flagSpace==false)
            input = removePunctuation(input, flagSpace);
        else if (flagCase == false && flagSpace==true)
            input = toLower(input);
        else
            input = removePunctuation(input ,flagSpace);
        //when input is at size 2, checks if the characters are equal
        if (input.size() == 2){
            if (input.at(0) != input.at(1)){
                palindrome = false;
            }
        }
    }
    else{
        if (flagCase==false && flagSpace==false){
            input = toLower(input);
            input = removePunctuation(input, flagSpace);
        }
        else if (flagCase == true && flagSpace==false)
            input = removePunctuation(input, flagSpace);
        else if (flagCase == false && flagSpace==true)
            input = toLower(input);
        else
            input = removePunctuation(input ,flagSpace);
        if (input.at(0) != input.at(input.size()-1)){
            palindrome = false;
        }
        //This creates a substring cutting off the first and last character
        input = input.substr(1,input.size()-2);
        //recursion checking for every other case with input being smaller and smaller
        if (isPalindrome(input,flagCase,flagSpace) == false){
            palindrome = false;
        }
    }
    return palindrome;
    
}
