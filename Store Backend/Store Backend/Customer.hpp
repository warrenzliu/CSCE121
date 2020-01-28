#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Product.hpp"
class Customer {
public:
    Customer(int, std::string, bool);
    int getID() const;
    std::string getName() const;
    void setName(std::string);
    bool getCredit() const;
    void setCredit(bool);
    double getBalance() const;
    void processPayment(double);
    void processPurchase(double, Product);
    std::string getProductsPurchased() const;
private:
    int id;
    std::string name;
    bool credit;
    double balance;
    std::vector<Product> productsPurchased;
    
};
std::ostream& operator<<(std::ostream&,const Customer&);
#endif 
