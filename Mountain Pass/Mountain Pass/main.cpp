#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "mountain.h"
using namespace std;
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G, vector<vector<int>>& B, int color_r, int color_g,int color_b, int start_row);
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G,
              vector<vector<int>>& B, int color_r, int color_g, int color_b,
              int start_row, int start_col);
int main(){
    int row,col;
    cin >> row; cin >> col;
    vector <vector <int>> data(row,vector<int>(col)); //creates a 2D vector based on input "row" and "col"
    string filename;
    cin >> filename; //takes the file name from user
    ifstream file {filename}; //opens the file
    ofstream output {filename+".ppm"};
    //This fills the 2D vector with values from fill
    for (int rows=0;rows<data.size();++rows){
        for(int col=0;col<data.at(rows).size();++col){
            int num;
            file >> num;
            data.at(rows).at(col)=num;
        }
    }
    //finds min and max
    int min = data.at(0).at(0) , max = data.at(0).at(0);
    for (int rows=0;rows<data.size();++rows){
        for(int col=0;col<data.at(rows).size();++col){
            if (min> data.at(rows).at(col))
                min = data.at(rows).at(col);
            if (max < data.at(rows).at(col))
                max = data.at(rows).at(col);
        }
    }
    //calculates the shade of gray and puts into vectors R,G,B
    vector <vector<int>> R(row, vector<int>(col));
    vector <vector<int>> G(row, vector<int>(col));
    vector <vector<int>> B(row, vector<int>(col));
    for (int rows=0;rows<data.size();++rows){
        for(int col=0;col<data.at(rows).size();++col){
            R.at(rows).at(col)=(255*(data.at(rows).at(col)-min)/(max-min));
            G.at(rows).at(col)=(255*(data.at(rows).at(col)-min)/(max-min));
            B.at(rows).at(col)=(255*(data.at(rows).at(col)-min)/(max-min));
        }
    }
    //This uses a loop to go through all the rows starting at column 0, after the loop, it paints the shortest path green
    int lowest = colorPath(data,R,G,B,252,25,63,0);
    int greenRow=0;
    for (int i = 0; i < row; ++i){
        colorPath(data,R,G,B,252,25,63,i);
        if (colorPath(data,R,G,B,252,25,63,i)< lowest){
            lowest = colorPath(data,R,G,B,252,25,63,i);
            greenRow=i;
        }
    }
    colorPath(data,R,G,B,31,253,13,greenRow);
    //This is the extra credit portion 
    int ec_row;
    int ec_column;
    if(cin >> ec_row >> ec_column) {
        colorPath(data,R,G,B,19,254,253,ec_row,ec_column);
    }
    
    
    //outputs to the file
    output << "P3" << endl;
    output << col << " " << row << endl;
    output << 255 << endl;
    for (int rows=0;rows<R.size();++rows){
        for(int col=0;col<R.at(rows).size();++col){
            output << R.at(rows).at(col) << " ";
            output << G.at(rows).at(col) << " ";
            output << B.at(rows).at(col) << " ";
            if (col == R.at(rows).size()-1)
                output << endl;
        }
    }
}
