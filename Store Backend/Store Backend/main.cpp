#include <iostream>
#include <string>
#include "Product.hpp"
#include "Customer.hpp"
#include "Store.hpp"
using namespace std;
int main(){
    try{
        
        Product a(32498,"Coozie");
        Product b(121212,"12th Man Towel");
        a.setDescription("A great way to keep a canned beverage cold.");
        b.setDescription("White towel with 12th man logo to wave when cheering Aggies to victory.");
        a.addShipment(83, 100);
        b.addShipment(12, 12.12);
        Customer test(2198123,"Miss Reveille",true);
        test.processPurchase(228.33, a);
        test.processPurchase(73.55, b);
        a.reduceInventory(13);
        /*
        cout << a.getNumberSold() << endl;
        cout <<a.getInventoryCount() << endl;
        cout << a.getTotalPaid() << endl;
        cout << a.getPrice() << endl;
        cout << test.getProductsPurchased() << endl;*/
        Store Walmart("Walmart");
        Walmart.addProduct(a.getID(), a.getName());
        Walmart.getProduct(a.getID()).addShipment(83, 100);
        Walmart.addProduct(b.getID(), b.getName());
        Walmart.addCustomer(test.getID(), test.getName());
        Walmart.takePayment(test.getID(), 201821);
        Walmart.listCustomers();
        Walmart.sellProduct(test.getID(), a.getID(), 30);
        
    }
    catch(runtime_error& except){
        cout << "Exception caught: " << except.what() << endl;
    }
}
