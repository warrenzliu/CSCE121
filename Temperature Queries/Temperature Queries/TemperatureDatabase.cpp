#include "TemperatureDatabase.hpp"
#include <fstream>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
    // Implement this function
    ifstream file (filename);
    while(!file.eof()){
        string location; int year; int month; double temperature;
        file >> location; file >> year; file >> month; file >> temperature;
        //uses bool variable to check if year,temperature,month are out of range
        bool check = false;
        if (year<1800 || year >2018){
            cout << "Error: year" << endl;
            check = true;
        }
        if ((temperature<-50 || temperature >50)&&temperature!=-99.99){
            cout << "Error: temperature" << endl;
            check = true;
        }
        if((month>12)||month<1){
            cout << "Error: months" << endl;
            check = true;
        }
        if (temperature != -99.99 && check != true)
            records.insert(location,year,month,temperature);
    }
    //records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
    // Implement this function
    ifstream file (filename);
    ofstream output {"result.dat"};
    string AVG = "AVG"; string MODE = "MODE";
    while(!file.eof()){
        string location; string query; int lowerYear; int higherYear;
        file >> location; file >> query; file >> lowerYear; file >> higherYear;
        if (lowerYear<1800||lowerYear>2018 || higherYear<1800||higherYear>2018|| higherYear<lowerYear)
            cout << "Error: year" << endl;
        if (query != AVG && query != MODE)
            cout << "Error: query" << endl;
        //makes sure that the lower year is less than or equal to higher year
        if (lowerYear<=higherYear && query == AVG){
            //output to file formating
            output << location << " "<< lowerYear << " " << higherYear << " " << AVG <<" ";
            if (records.getAverage(location, lowerYear, higherYear)==-99.99){
                output<<"unknown" << endl;
            }
            else{
                output << records.getAverage(location, lowerYear, higherYear) << endl;
            }
        }
        if (lowerYear<=higherYear && query == MODE){
            output << location << " "<< lowerYear << " " << higherYear << " " << MODE <<" ";
            if (records.getMode(location, lowerYear, higherYear)==-99){
                output<< "unknown" << endl;
            }
            else{
                output << records.getMode(location, lowerYear, higherYear) << endl;
            }
        }
    }
}
