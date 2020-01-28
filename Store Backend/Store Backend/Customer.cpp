#include "Customer.hpp"
#include "Product.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;
Customer::Customer(int customerID, string name, bool credit): id(customerID), name(name), credit(credit), balance(0.0){
    if (name.size() == 0)
        throw runtime_error("The name cannot be empty.");
}
//All the get functions
int Customer::getID() const{ return id; }
string Customer::getName() const{ return name; }
bool Customer::getCredit() const{ return credit; }
double Customer::getBalance() const{ return balance; }
string Customer::getProductsPurchased() const{
    string productNames;
    ostringstream outputNames;
    //uses string stream to return one string that contains the correct format
    outputNames << "--" << endl << endl;
    for(int i = 0; i < productsPurchased.size();i++){
        outputNames << productsPurchased.at(i) << endl;
    }
    productNames = outputNames.str();
    return productNames;
}

//set funcitons
void Customer::setName(string name) {
    if (name.size() == 0)
        throw runtime_error("The name cannot be empty.");
    this->name = name;
}
void Customer::setCredit(bool hasCredit){
    this->credit = hasCredit;
}

void Customer::processPayment(double amount) {
    if (amount < 0)
        throw runtime_error("Amount cannot be negative.");
    balance += amount;
}
void Customer::processPurchase(double amount, Product product){
    bool sameName = false;
    if (amount < 0)
        throw runtime_error("Amount cannot be negative.");
    if (credit == true)
        balance -= amount;
    if (credit == false){
        if (balance >= amount)
            balance -= amount;
        else
            throw runtime_error("Amount exceeds balance amount");
    }
    for (int i = 0; i<productsPurchased.size(); i++){
        if (productsPurchased.at(i).getName() == product.getName()){
            sameName = true;
        }
    }
    //checks if the products are the same name and doesn't add the product if they are
    if (!sameName){
        productsPurchased.push_back(product);
    }
}
std::ostream& operator<<(std::ostream& output,const Customer& customer){
    string credit;
    //returns the word true or false
    if(customer.getCredit())
        credit = "true";
    else
        credit = "false";
    output << "Customer Name: " << customer.getName() << endl;
    output << "Customer ID: " << customer.getID() << endl;
    output << "Has Credit: " << credit << endl;
    output << "Balance: " << customer.getBalance() << endl;
    output << "Products purchased " << customer.getProductsPurchased() << endl;
    return output;
}

