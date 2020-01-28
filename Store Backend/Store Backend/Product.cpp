#include "Product.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
Product::Product(int id,string name): id(id), name(name), description(""), numSold(0), inventory(0), totalPaid(0.0){
    if (name.size() == 0)
        throw runtime_error("The name cannot be empty.");
}
int Product::getID() const{ return id; }
string Product::getName() const{ return name; }
void Product::setName(string name) {
    if (name.size() == 0)
        throw runtime_error("The product name cannot be empty.");
    this->name = name;
}
string Product::getDescription() const{ return description; }
void Product::setDescription(string description){
    this->description = description;
}
int Product::getNumberSold() const{ return numSold; }
double Product::getTotalPaid() const{ return totalPaid; }
int Product::getInventoryCount() const{ return inventory;}
void Product::addShipment(int shipmentQuantity,double shipmentCost){
    if (shipmentQuantity < 0)
        throw runtime_error("Shipment quantity cannot be negative.");
    if (shipmentCost < 0)
        throw runtime_error("Shipment cost cannot be negative.");
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
}
void Product::reduceInventory(int purchaseQuantity){
    if (purchaseQuantity > inventory)
        throw runtime_error("Not enough inventory.");
    if (purchaseQuantity < 0)
        throw runtime_error("Purchase quantity cannot be negative.");
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
}
double Product::getPrice() const{
    double price = (totalPaid/(inventory+numSold+0.0))*1.25;
    return price;
}
std::ostream& operator<<(std::ostream& output,const Product& product){
    output << "Product Name: " << product.getName() << endl;
    output << "Product ID: " << product.getID() << endl;
    output << "Description: " << product.getDescription() << endl;
    output << "Inventory: " << product.getInventoryCount() << endl;
    output << "Total Paid: " << product.getTotalPaid() << endl;
    return output;
}
