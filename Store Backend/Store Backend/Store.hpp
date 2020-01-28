
#ifndef Store_hpp
#define Store_hpp
#include <stdio.h>
#include <string>
#include "Product.hpp"
#include "Customer.hpp"
#include <vector>
class Store{
public:
    Store();
    Store(std::string);
    std::string getName() const;
    void setName(std::string);
    void addProduct(int, std::string);
    Product& getProduct(int);
    void addCustomer(int customerID, std::string customerName, bool credit=false);
    Customer& getCustomer(int customerID);
    void takeShipment(int productID, int quantity, double cost);
    void sellProduct(int customerID, int productID, int quantity);
    void takePayment(int customerID, double amount);
    void listProducts() const;
    void listCustomers() const;
private:
    std::string name;
    std::vector<Customer> customers;
    std::vector<Product> products;
};

#endif
