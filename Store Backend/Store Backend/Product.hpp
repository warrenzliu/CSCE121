
#ifndef Product_hpp
#define Product_hpp
#include <stdio.h>
#include <string>
class Product {
public:
    Product(int,std::string);
    int getID () const;
    std::string getName () const;
    void setName (std::string);
    std::string getDescription() const;
    void setDescription (std::string);
    int getNumberSold() const;
    double getTotalPaid ()const;
    int getInventoryCount ()const;
    double getPrice() const;
    void addShipment(int,double);
    void reduceInventory(int);
private:
    int id;
    std::string name;
    std::string description;
    int inventory;
    int numSold;
    double totalPaid;
};
std::ostream& operator<<(std::ostream&,const Product&);
#endif
