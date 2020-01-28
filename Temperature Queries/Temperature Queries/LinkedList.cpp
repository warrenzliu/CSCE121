#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include <vector>
#include <algorithm>
using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr){
    // Implement this function *done
}

LinkedList::~LinkedList() {
    // Implement this function *done
    clear();
    cout << "Linkedlist destructor called" << endl;
}
LinkedList::LinkedList(const LinkedList& source) {
    // Implement this function
    //copies the Linkedlist source to the this parameter
    Node* node = source.head;
    while(node!=nullptr){
        this->insert(node->id,node->year,node->month,node->temperature);
        node = node->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    // Implement thi s function
    if (this != &source){
        clear();
        Node* node = source.head;
        while(node!=nullptr){
            this->insert(node->id,node->year,node->month,node->temperature);
            node = node->next;
        }
    }
    return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
    // Implement this function//
    Node* newNode = new Node(location,year,month,temperature);
    //checks if the linkedlist is empty
    if (head == nullptr && tail== nullptr){
        head = newNode; tail=newNode;
        newNode->next = nullptr;
    }
    //checks if the newNode is less than the head, if it is insert before head
    if (*newNode < *head){
        newNode->next = head;
        head = newNode;
    }
    //checks if the newNode is greater than tail, if it is insert after tail
    else if (*tail<*newNode){
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    //checks everywhere inbetween and inserts accordingly
    else{
        Node* curr = head;
        while (curr != nullptr){
            if ((*curr < *newNode)&&curr->next!=nullptr &&(*newNode < *(curr->next))){
                newNode->next = curr->next;
                curr->next = newNode;
                break;
            }
            curr = curr->next;
        }
    }
    
}

void LinkedList::clear() {
    // Implement this function *done
    //deletes everything in the linkelist
    Node* Head = getHead();
    while(Head != nullptr){
        Node* temp = Head->next;
        delete Head;
        Head = temp;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const {
    /* Do not modify this function */
    print(cout);
}

void LinkedList::print(ostream& os) const {
     /*Do not modify this function*/
    os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
    // Implement this function
    //outputs id,year,month,temperature of every node to the ostream
    Node* Head = ll.getHead();
    while(Head != nullptr){
        os << Head->id << " ";
        os << Head->year << " ";
        os << Head->month << " ";
        os << Head->temperature << endl;
        Head = Head->next;
    }
    return os;
}
Node* LinkedList::getHead() const{
    return head;
}
double LinkedList::getAverage(string location,int lowerYear,int higherYear) const{
    double sum = 0.0;
    int count = 0;
    Node* curr = head;
    while(curr != nullptr){
        //if statement to make sure the node is within the range we want
        if (curr->id == location && curr->year >= lowerYear && curr->year <= higherYear){
            sum += curr->temperature;
            count += 1;
        }
        curr = curr->next;
    }
    if (sum == 0.0)
        //just to know if we need to return "unknown"
        return -99.99;
    return (sum/count);
}
int LinkedList::getMode(string location,int lowerYear,int higherYear) {
    vector<int> values(0);
    Node* curr = head;
    while (curr!= nullptr){
        //if statement to make sure the node is within the range we want
         if (curr->id == location && curr->year >= lowerYear && curr->year <= higherYear){
             //adds all the rounded nodes within the range to the vector
             int temp = round(curr->temperature);
             values.push_back(temp);
         }
        curr=curr->next;
    }
    //sorts all the values from least to greatest
    sort(values.begin(),values.end());
    if (values.size()==0)
        //just to know if we need to return "unknown"
        return -99;
    int value = values.at(0);
    int count = 0; //starts at 0 in order to n ot double count the first value in vector
    int countSave = 1;
    int mode = 0;
    for (int i = 0; i < values.size(); ++i){
        if (value == values.at(i)){
            count += 1;
        }
        else{
            count = 1; //set to 1 because if it's 0, then the function would return the lowest number if they all have same mode
            value = values.at(i);
        }
        //checks if the count the for loop is currently at is more or equal to the greatest count (countSave) and replaces if it is
        if (count >= countSave){
            countSave = count;
            mode = values.at(i);
        }
    }
    return mode;
}

int LinkedList::round(double num){
    //rounds the values by using integer truncation, then subtract truncation number to the original number to get decimal, compares decimal to 0.51 and rounds accordingly
    int check = num;
    double decimal = num-check;
    bool roundUp = false;
    if (decimal >= 0.51){
        roundUp = true;
    }
    if (roundUp){
        double remaining = 1-decimal;
        num += remaining;
    }
    else{
        num -= decimal;
    }
    return num;
}
