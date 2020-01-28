#include "TemperatureDatabase.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " data_file query_file" << endl;
        return 1;
    } else {
        TemperatureDatabase database;
        database.loadData(argv[1]);
        database.performQuery(argv[2]);
    }
    /*
    string file;
    TemperatureDatabase database;
    file = "s050_TX-2000-2015.dat";
    database.loadData(file);
    database.performQuery("queries-2000s.dat");
     */
}

