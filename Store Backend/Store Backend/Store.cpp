#include "Store.hpp"
#include <iostream>
#include <string>
using namespace std;
Store::Store():name(""){}
Store::Store(string name):name(name){
    if (name.size() == 0)
        throw runtime_error("The name cannot be empty.");
}
string Store::getName() const{ return name; }
void Store::setName(string name){
    this->name = name;
}
void Store::addProduct(int productID, string productName){
    for (int i = 0; i < products.size(); i++){
        //check through the vector to see if productID matches something in vector
        if (productID == products.at(i).getID()){
            throw runtime_error("The Product ID already exists");
        }
    }
    //if no error thrown then add to vector
    Product product = Product(productID,productName);
    products.push_back(product);
}
Product& Store::getProduct(int productID){
    for (int i = 0; i <products.size(); i++){
        if (products.at(i).getID() == productID){
            return products.at(i);
        }
    }
    //if didn't return, then throw error
    throw runtime_error("There isn't a product with that ID in the list");
}
void Store::addCustomer(int customerID, string customerName, bool credit){
    for (int i = 0; i < customers.size(); i++){
        if (customers.at(i).getID() == customerID){
            throw runtime_error("There is already a customer with that ID");
        }
    }
    Customer customer = Customer (customerID,customerName,credit);
    customers.push_back(customer);
}
Customer& Store::getCustomer(int customerID){
    for (int i = 0; i <customers.size(); i++){
        if (customers.at(i).getID() == customerID){
            return customers.at(i);
        }
    }
    throw runtime_error("There isn't a customer with that ID in the list");
}
void Store::takeShipment(int productID, int quantity, double cost){
    bool check = true; //need bool variable in order to check if productID matches something in vector
    for (int i = 0; i < products.size(); i++){
        if (products.at(i).getID() == productID){
            products.at(i).addShipment(quantity, cost);
            check = false;
        }
    }
    if (check){
        throw runtime_error("Product with match productID not found");
    }
}
void Store::sellProduct(int customerID, int productID, int quantity){
    bool customerCheck = false;
    bool productCheck = false;
    int productNum = 0;
    int customerNum = 0;
    for (int i = 0; i <products.size(); i++){
        if (products.at(i).getID() == productID){
            productCheck = true; //used for later in if statement
            productNum = i;//gives the location of where the match was
        }
    }
    for (int i = 0; i <customers.size(); i++){
        if (customers.at(i).getID() == customerID){
            customerCheck = true;
            customerNum = i;
        }
    }
    double amount = quantity * products.at(productNum).getPrice();
    if (productCheck && customerCheck){ //makes sure that both are true in order to continue
        customers.at(customerNum).processPurchase(amount, products.at(productNum));
        products.at(productNum).reduceInventory(quantity);
    }
}
void Store::takePayment(int customerID, double amount){
    for (int i = 0; i <customers.size(); i++){
        if (customers.at(i).getID() == customerID){
            customers.at(i).processPayment(amount);
        }
    }
}
void Store::listProducts() const{
    for (int i = 0; i < products.size(); i++){
        cout << products.at(i) << endl;
    }
}
void Store::listCustomers() const{
    for (int i = 0; i < customers.size(); i++){
        cout << customers.at(i) << endl;
    }
}
