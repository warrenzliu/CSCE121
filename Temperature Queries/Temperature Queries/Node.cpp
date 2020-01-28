#include <string>
#include "Node.hpp"

using namespace std;

// Default constructor
Node::Node():next(nullptr),id(""), year(0), month(0), temperature(0.0) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature): next(nullptr), id(id), year(year), month(month), temperature(temperature){}
// remember to initialize next to nullptr

//compares first node to the second based on id,year,month and finally temperature
bool Node::operator<(const Node& second) {
    if (this->id < second.id){
        return true;
    }
    else if(this->id == second.id){
        if (this->year <second.year){
            return true;
        }
        else if (this->year == second.year){
            if(this->month <second.month){
                return true;
            }
            else if (this-> month == second.month){
                if (this->temperature <second.temperature){
                    return true;
                }
            }
        }
    }
    return false;
}
