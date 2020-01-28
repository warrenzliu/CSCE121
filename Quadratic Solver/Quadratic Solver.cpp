//
//  Quadratic Solver.cpp
//  CS homework1
//
//  Created by Ting Liu on 1/25/18.
//  Copyright © 2018 Ting Liu. All rights reserved.
//

#include "Quadratic Solver.hpp"
#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;
    if ((a==0)&&(b==0)&&(c==0)){
        cout << "Unable to determine roots." << endl;
    }
    if ((a==0)&&(c==0)){
        cout << "x = 0" << endl;
    }
    if (a==0){
        cout << "x = " << -c/b << endl;
    }
    
    cout << a << "x^2"<< " + " << b << "x" << " + " << c << " = 0" << endl;
    
    
    
    
}
