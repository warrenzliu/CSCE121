#include<iostream>
#include<vector>
#include<iomanip>
#include<ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int ROWS = 5;
    vector<vector<int>> card(ROWS, vector<int>(ROWS, -1));
    
    /*for (int row=0; row < ROWS; ++row) {
     for (int col=0; col < ROWS; ++col) {
     cout << setw(3) << card.at(row).at(col);
     }
     cout << endl;
     }*/
    
    int maxval = 15;
    for (int col=0; col<ROWS; ++col) {
        vector<int> bag;
        for (int i=1; i<=maxval; ++i) {
            bag.push_back(i);
        }
        for (int row=0; row<ROWS; ++row) {
            int randIndex = rand()%bag.size();
            card.at(row).at(col) = bag.at(randIndex) + col*maxval;
            bag.erase(bag.begin() + randIndex);
        }
    }
    // set middle to free
    card.at(ROWS/2).at(ROWS/2) = 0;
    
    
    bool won = false;
    while (!won) {
        cout << setw(3) << "B";
        cout << setw(3) << "I";
        cout << setw(3) << "N";
        cout << setw(3) << "G";
        cout << setw(3) << "O" << endl;
        for (int row=0; row < ROWS; ++row) {
            for (int col=0; col < ROWS; ++col) {
                if (card.at(row).at(col) == 0 )
                    cout << setw(3) << 'F';
                else
                    cout << setw(3) << card.at(row).at(col);
            }
            cout << endl;
        }
        
        char colCalled;
        int numCalled;
        cout << "Enter Column (B, I, N, G, O) and number:";
        cin >> colCalled >> numCalled;
        
        // mark
        int col = (numCalled - 1) / maxval;
        for (int row = 0; row < ROWS; ++row)
            if (card.at(row).at(col)==numCalled)
                card.at(row).at(col) *= -1;
        
        // check for win
        
        int row = 0;
        while (row < ROWS && !won) {
            bool rowWon = true;
            col = 0;
            while (col < ROWS && rowWon) {
                if (card.at(row).at(col) > 0)
                    rowWon = false;
                col++;
            }
            if (rowWon) won = true;
            row++;
        }
        
        // check columns
        col = 0;
        while (col < ROWS && !won) {
            bool colWon = true;
            row = 0;
            while (row < ROWS && colWon) {
                if (card.at(row).at(col) > 0)
                    colWon = false;
                row++;
            }
            if (colWon) won = true;
            col++;
        }
        
        if (!won) {
            // check diagonal
            bool diagWon = true;
            int index = 0;
            while (diagWon && index < ROWS) {
                if (card.at(index).at(index) > 0)
                    diagWon = false;
                index++;
            }
            if (diagWon) won = true;
        }
        
        if (!won) {
            // check diagonal
            bool diagWon = true;
            int index = ROWS - 1;
            while (diagWon && index >= 0) {
                if (card.at(index).at(ROWS - 1 - index) > 0)
                    diagWon = false;
                index--;
            }
            if (diagWon) won = true;
        }
        
        
        
    }
    
    cout << setw(3) << "B";
    cout << setw(3) << "I";
    cout << setw(3) << "N";
    cout << setw(3) << "G";
    cout << setw(3) << "O" << endl;
    for (int row=0; row < ROWS; ++row) {
        for (int col=0; col < ROWS; ++col) {
            if (card.at(row).at(col) == 0 )
                cout << setw(3) << 'F';
            else
                cout << setw(3) << card.at(row).at(col);
        }
        cout << endl;
    }
    
    if (won) cout << "You won!" << endl;
    
    
}
