//
//  LinkedList.hpp
//  Temperature Queries
//
//  Created by Ting Liu on 4/12/18.
//  Copyright © 2018 Ting Liu. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <string>
#include "Node.hpp"

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Default constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Copy constructor
    LinkedList(const LinkedList& other);
    
    // Assignment constructor
    LinkedList& operator=(const LinkedList& other);
    
    // Insert a record to the linked list
    void insert(std::string location, int year, int month, double temperature);
    
    // Clear the content of this linked list
    void clear();
    
    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
    Node* getHead() const;
    double getAverage(std::string,int,int) const;
    int getMode(std::string,int,int);
    int round(double);
    
    
    // The functions below are written already. Do not modify them.
    void print() const;
    void print(std::ostream&) const;
    
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif

