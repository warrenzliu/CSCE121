#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(0));
    int numAdd;
    int numDigits;
    int code;
    int loc;
    int guess;
    int bulls = 0;
    int cows = 0;
    bool exitLoop;
    bool cont = true;
    bool win = false;
    bool dont_print = false;
    
    //Asks the question until your enter 3, 4, 5 or 0
    do{
        cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> numDigits;
        cout << endl;
    }
    while (numDigits != 3 && numDigits != 4 && numDigits !=5 && numDigits !=0);
    
    vector<int> codeDigits;
    vector<int> vecDigits;
    vector<int> bag(10);
    vector<int> guessDigits;
    
    //adds values from 0-9 into the vector "bag"
    for (int i = 0; i < bag.size(); i++){
        bag.at(i) = i;
    }
    
    if (numDigits == 0){
        cout << "Enter code: ";
        cin >> code;
        cout << endl;
        cout << "Enter number of digits in code: ";
        cin >> numDigits;
        cout << endl;
        
        //This takes the variable "code" and puts it into the vector "codeDigits"
        for (int i = 10000; i > 0; i/=10){
            codeDigits.push_back(code/i);
            code = code - ((code/i)*i);
        }
        cout << "Number to guess: ";
        
        //This erases any extra 0s in the vector, because if the number is 23, then the vector will contain 00023, a break is used to stop from deleting 0s in the actual number such as 50
        while (codeDigits.at(0)==0){
            codeDigits.erase(codeDigits.begin());
        }
        
        //inserts 0s while numDigits is greater than the length of the vector that contains "code"
        while (numDigits > codeDigits.size()){
            codeDigits.insert(codeDigits.begin(), 0);
        }
        
        //prints out the contents of the vector "codeDigits"
        for (int i = 0; i < codeDigits.size(); ++i){
            cout << codeDigits.at(i);
        }
        cout << endl;
        while (!win){
            //This while loop checks for multiple numbers in a guess and makes the user guess again if there is multiple numbers
            while (cont){
                cout << "Enter guess: ";
                cin >> guess;
                cout << endl;
                cont = false;
                exitLoop = false;
                dont_print=false;
                if (guess == 0){
                    cout << "Each number must be different." << endl;
                    cont = true;
                    dont_print= true;
                    break;
                }
                //erases contents of the vector in order to have multiple guesses
                while (guessDigits.size()>0){
                    guessDigits.erase(guessDigits.begin());
                }
                //This is the same as above, but instead of code being added to a vector, it's guess now
                for (int i = 10000; i > 0; i/=10){
                    guessDigits.push_back(guess/i);
                    guess = guess - ((guess/i)*i);
                }
                while (guessDigits.at(0)==0){
                    if (guessDigits.size()>1)
                        guessDigits.erase(guessDigits.begin());
                }
                while (numDigits > guessDigits.size()){
                    guessDigits.insert(guessDigits.begin(), 0);
                }
                //This checks for mutliple numbers in a guess and takes account of special cases like if the for loop checks for the same value (i==j)
                for (int i = 0; i < guessDigits.size() && !exitLoop; ++i){
                    for (int j = 0; j < guessDigits.size() && !exitLoop; ++j){
                        if (i==j)
                            break;
                        if (numDigits<guessDigits.size()){
                            cout << "You can only enter " << numDigits << " digits." << endl;
                            cont = true;
                            exitLoop = true;
                            break;
                        }
                        if (guessDigits.at(i)==guessDigits.at(j)){
                            cout << "Each number must be different." << endl;
                            exitLoop = true;
                            cont = true;
                        }
                    }
                }
            }
            //for loop to check for bulls and if bulls equal the number of digits, prints out winner
            for (int i=0; i < guessDigits.size(); ++i){
                if (codeDigits.at(i)==guessDigits.at(i)){
                    bulls += 1;
                }
                if (bulls == numDigits){
                    cout << bulls << " bulls - ";
                    for (int i = 0; i < codeDigits.size(); ++i){
                        cout << codeDigits.at(i);
                    }
                    cout << " is Correct!" << endl;
                    win = true;
                    break;
                }
            }
            //checks for cows by checking every integer with another one, then subtracting any bulls
            for (int i = 0; i < guessDigits.size(); ++i){
                for (int j = 0; j < guessDigits.size(); ++j){
                    if (i==j && codeDigits.at(i)==guessDigits.at(j)){
                        cows -= 1;
                    }
                    if (codeDigits.at(i)==guessDigits.at(j)){
                        cows += 1;
                    }
                }
            }
            cont = true; //This line makes it so after the number of cows and bulls are calculated, the code asks for another "guess". Without this, there would be an infinite loop.
            if (win!=true && !dont_print){
                cout << bulls << " bulls" << endl;
                cout << cows << " cows" << endl;
            }
            //resets value of bulls and cows so someone doesn't win without winning
            bulls = 0;
            cows = 0;
        }
    }
    
    //generates a random number by taking numDigits values from the vector "bag" and placing it in the vector "vecDigits"
    else{
        for (int i = 0; i < numDigits; ++i){
            loc = rand() % (10-i);
            numAdd = bag.at(loc);
            vecDigits.push_back(numAdd);
            bag.erase(bag.begin()+loc);
        }
        cout << "Number to guess: ";
        //prints out the contents of vector "vecDigits"
        for (int i = 0; i < vecDigits.size(); ++i){
            cout << vecDigits.at(i);
        }
        cout << endl;
        
        //All of this was copy pasted from above, except codeDigits was changed to vecDigits
        while (!win){
            while (cont){
                cout << "Enter guess: ";
                cin >> guess;
                cont = false;
                exitLoop = false;
                dont_print = false;
                if (guess == 0){
                    cout << "Each number must be different." << endl;
                    cont = true;
                    dont_print= true;
                    break;
                }
                while (guessDigits.size()>0){
                    guessDigits.erase(guessDigits.begin());
                }
                for (int i = 10000; i > 0; i/=10){
                    guessDigits.push_back(guess/i);
                    guess = guess - ((guess/i)*i);
                }
                while (guessDigits.at(0)==0){
                    guessDigits.erase(guessDigits.begin());
                }
                while (numDigits > guessDigits.size()){
                    guessDigits.insert(guessDigits.begin(), 0);
                }
                for (int i = 0; i < guessDigits.size() && !exitLoop; ++i){
                    for (int j = 0; j < guessDigits.size() && !exitLoop; ++j){
                        if (i==j)
                            break;
                        if (numDigits<guessDigits.size()){
                            cout << "You can only enter " << numDigits << " digits." << endl;
                            cont = true;
                            exitLoop = true;
                            break;
                        }
                        if (guessDigits.at(i)==guessDigits.at(j)){
                            cout << "Each number must be different." << endl;
                            exitLoop = true;
                            cont = true;
                        }
                    }
                }
            }
            for (int i=0; i < guessDigits.size(); ++i){
                if (vecDigits.at(i)==guessDigits.at(i)){
                    bulls += 1;
                }
                if (bulls == numDigits){
                    cout << bulls << " bulls - ";
                    for (int i = 0; i < vecDigits.size(); ++i){
                        cout << vecDigits.at(i);
                    }
                    cout << " is Correct!" << endl;
                    win = true;
                    break;
                }
            }
            for (int i = 0; i < guessDigits.size(); ++i){
                for (int j = 0; j < guessDigits.size(); ++j){
                    if (i==j && vecDigits.at(i)==guessDigits.at(j)){
                        cows -= 1;
                    }
                    if (vecDigits.at(i)==guessDigits.at(j)){
                        cows += 1;
                    }
                }
            }
            cont = true; //This line makes it so after the number of cows and bulls are calculated, the code asks for another "guess". Without this, there would be an infinite loop.
            if (win!=true &&!dont_print){
                cout << bulls << " bulls" << endl;
                cout << cows << " cows" << endl;
            }
            bulls = 0;
            cows = 0;
        }
    }
}
