#include <vector>
#include <cmath>
#include "mountain.h"
using namespace std;
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G, vector<vector<int>>& B, int color_r, int color_g,int color_b, int start_row){
    int col = 0;
    int dist = 0;
    bool stop = true;
    //paints the starting point the color
    R.at(start_row).at(col)=color_r;
    G.at(start_row).at(col)=color_g;
    B.at(start_row).at(col)=color_b;
    //Checks for when the starting point is at the very top
    while (start_row==0 && stop){
        //This breaks out of the loop
        if (col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        //creates variables inside the while loop so they reset
        int elevationMiddle = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
        int elevationLow = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row+1).at(col+1));
        if (elevationLow<elevationMiddle){
            start_row +=1;
            col += 1;
            dist += elevationLow;
        }
        else{
            col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(col)=color_r;
        G.at(start_row).at(col)=color_g;
        B.at(start_row).at(col)=color_b;
        //since the position can move after starting at the top, this while loop is needed
        while (start_row>0){
            if (col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row-1).at(col+1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
            int elevationLow=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row+1).at(col+1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                col += 1;
                dist += elevationHigh;
                
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                col += 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row +=1 ;
                col += 1;
                dist += elevationLow;
            }
            else{
                col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(col)=color_r;
            G.at(start_row).at(col)=color_g;
            B.at(start_row).at(col)=color_b;
        }
    }
    //Checks for starting point at the very bottom
    while (start_row == heightMap.size()-1 && stop){
        if (col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
        int elevationHigh=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row-1).at(col+1));
        if (elevationHigh<elevationMiddle){
            start_row -= 1;
            col += 1;
            dist += elevationHigh;
        }
        else {
            col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(col)=color_r;
        G.at(start_row).at(col)=color_g;
        B.at(start_row).at(col)=color_b;
        while (start_row<heightMap.size()-1){
            if (col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row-1).at(col+1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
            int elevationLow=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row+1).at(col+1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                col += 1;
                dist += elevationHigh;
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                col += 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row +=1 ;
                col += 1;
                dist += elevationLow;
            }
            else{
                col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(col)=color_r;
            G.at(start_row).at(col)=color_g;
            B.at(start_row).at(col)=color_b;
        }
    }
    //checks starting point in the middle
    while (start_row < heightMap.size()-1 && stop && start_row != 0 && start_row != heightMap.size()-1){
        if (col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        int elevationHigh=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row-1).at(col+1));
        int elevationMiddle=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
        int elevationLow=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row+1).at(col+1));
        if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
            start_row -= 1;
            col += 1;
            dist += elevationHigh;
        }
        else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
            start_row += 1;
            col += 1;
            dist += elevationLow;
        }
        else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
            start_row +=1 ;
            col += 1;
            dist += elevationLow;
        }
        else{
            col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(col)=color_r;
        G.at(start_row).at(col)=color_g;
        B.at(start_row).at(col)=color_b;
        while (start_row==0){
            if (col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
            int elevationLow = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row+1).at(col+1));
            if (elevationLow<elevationMiddle){
                start_row += 1;
                col += 1;
                dist += elevationLow;
            }
            else{
                col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(col)=color_r;
            G.at(start_row).at(col)=color_g;
            B.at(start_row).at(col)=color_b;
        }
        while (start_row == heightMap.size()-1){
            if (col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row).at(col+1));
            int elevationHigh=fabs(heightMap.at(start_row).at(col)-heightMap.at(start_row-1).at(col+1));
            if (elevationHigh<elevationMiddle){
                start_row -= 1;
                col += 1;
                dist += elevationHigh;
            }
            else {
                col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(col)=color_r;
            G.at(start_row).at(col)=color_g;
            B.at(start_row).at(col)=color_b;
        }
    }
    return dist;
}


//------------------------------------FUNCTION BREAK------------------------------------------------
//------------------------------------FUNCTION BREAK------------------------------------------------
//------------------------------------FUNCTION BREAK------------------------------------------------
//------------------------------------FUNCTION BREAK------------------------------------------------
//All of these are variations of the code above

//-------------------------------------------EAST---------------------------------------------------

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G,
              vector<vector<int>>& B, int color_r, int color_g, int color_b,
              int start_row, int start_col){
    int holderRow = start_row;
    int holderCol = start_col;
    int dist = 0;
    bool stop = true;
    R.at(start_row).at(start_col)=color_r;
    G.at(start_row).at(start_col)=color_g;
    B.at(start_row).at(start_col)=color_b;
    while (start_row==0 && stop){
        if (start_col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
        int elevationLow = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
        if (elevationLow<elevationMiddle){
            start_row +=1;
            start_col += 1;
            dist += elevationLow;
        }
        else{
            start_col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row>0){
            if (start_col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
            int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                start_col += 1;
                dist += elevationHigh;
                
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                start_col += 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row +=1 ;
                start_col += 1;
                dist += elevationLow;
            }
            else{
                start_col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_row == heightMap.size()-1 && stop){
        if (start_col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
        int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
        if (elevationHigh<elevationMiddle){
            start_row -= 1;
            start_col += 1;
            dist += elevationHigh;
        }
        else {
            start_col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row<heightMap.size()-1){
            if (start_col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
            int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                start_col += 1;
                dist += elevationHigh;
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                start_col += 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row +=1 ;
                start_col += 1;
                dist += elevationLow;
            }
            else{
                start_col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_row < heightMap.size()-1 && stop && start_row != 0 && start_row != heightMap.size()-1){
        if (start_col == heightMap.at(start_row).size()-1){
            stop = false;
            break;
        }
        int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
        int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
        int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
        if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
            start_row -= 1;
            start_col += 1;
            dist += elevationHigh;
        }
        else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
            start_row += 1;
            start_col += 1;
            dist += elevationLow;
        }
        else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
            start_row +=1 ;
            start_col += 1;
            dist += elevationLow;
        }
        else{
            start_col += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row==0){
            if (start_col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
            int elevationLow = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationLow<elevationMiddle){
                start_row += 1;
                start_col += 1;
                dist += elevationLow;
            }
            else{
                start_col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
        while (start_row == heightMap.size()-1){
            if (start_col == heightMap.at(start_row).size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col+1));
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            if (elevationHigh<elevationMiddle){
                start_row -= 1;
                start_col += 1;
                dist += elevationHigh;
            }
            else {
                start_col += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    //--------------------------------------------------------------------------------------------------
    //-------------------------------------------WEST---------------------------------------------------
    //--------------------------------------------------------------------------------------------------
    start_row = holderRow;
    start_col = holderCol;
    stop = true;
    while (start_row==0 && stop){
        if (start_col == 0){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
        int elevationLow = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
        if (elevationLow<elevationMiddle){
            start_row +=1;
            start_col -= 1;
            dist += elevationLow;
        }
        else{
            start_col -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row>0){
            if (start_col == 0){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
            int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                start_col -= 1;
                dist += elevationHigh;
                
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                start_col -= 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row -=1 ;
                start_col -= 1;
                dist += elevationLow;
            }
            else{
                start_col -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_row == heightMap.size()-1 && stop){
        if (start_col == 0){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
        int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
        if (elevationHigh<elevationMiddle){
            start_row -= 1;
            start_col -= 1;
            dist += elevationHigh;
        }
        else {
            start_col -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row<heightMap.size()-1){
            if (start_col == 0){
                stop = false;
                break;
            }
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
            int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
                start_row -= 1;
                start_col -= 1;
                dist += elevationHigh;
            }
            else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
                start_row += 1;
                start_col -= 1;
                dist += elevationLow;
            }
            else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
                start_row -= 1 ;
                start_col -= 1;
                dist += elevationLow;
            }
            else{
                start_col -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_row < heightMap.size()-1 && stop && start_row != 0 && start_row != heightMap.size()-1){
        if (start_col == 0){
            stop = false;
            break;
        }
        int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
        int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
        int elevationLow=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
        if (elevationHigh<elevationMiddle && elevationHigh < elevationLow){
            start_row -= 1;
            start_col -= 1;
            dist += elevationHigh;
        }
        else if (elevationLow<elevationMiddle && elevationLow < elevationHigh){
            start_row += 1;
            start_col -= 1;
            dist += elevationLow;
        }
        else if (elevationLow==elevationHigh && elevationLow<elevationMiddle && elevationHigh<elevationMiddle){
            start_row -= 1 ;
            start_col -= 1;
            dist += elevationLow;
        }
        else{
            start_col -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_row==0){
            if (start_col == 0){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
            int elevationLow = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            if (elevationLow<elevationMiddle){
                start_row += 1;
                start_col -= 1;
                dist += elevationLow;
            }
            else{
                start_col -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
        while (start_row == heightMap.size()-1){
            if (start_col == 0){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row).at(start_col-1));
            int elevationHigh=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            if (elevationHigh<elevationMiddle){
                start_row -= 1;
                start_col -= 1;
                dist += elevationHigh;
            }
            else {
                start_col -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    //--------------------------------------------------------------------------------------------------
    //----------------------------------------NORTH-----------------------------------------------------
    //--------------------------------------------------------------------------------------------------
    start_row = holderRow;
    start_col = holderCol;
    stop = true;
    while (start_col==0 && stop){
        if (start_row == 0){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
        int elevationRight = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
        if (elevationRight<elevationMiddle){
            start_row -= 1;
            start_col += 1;
            dist += elevationRight;
        }
        else{
            start_row -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col>0){
            if (start_row == 0){
                stop = false;
                break;
            }
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
            int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
                start_row -= 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
                start_row -= 1;
                start_col += 1;
                dist += elevationLeft;
            }
            else if (elevationLeft==elevationRight && elevationLeft<elevationMiddle && elevationLeft<elevationMiddle){
                start_row -= 1;
                start_col += 1;
                dist += elevationRight;
            }
            else{
                start_row -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_col == heightMap.at(start_row).size()-1 && stop){
        if (start_row == 0){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
        int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
        if (elevationLeft<elevationMiddle){
            start_row -= 1;
            start_col -= 1;
            dist += elevationLeft;
        }
        else {
            start_row -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col<heightMap.at(start_row).size()-1){
            if (start_row == 0){
                stop = false;
                break;
            }
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
            int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
                start_row -= 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
                start_row -= 1;
                start_col += 1;
                dist += elevationRight;
            }
            else if (elevationRight==elevationLeft && elevationRight<elevationMiddle && elevationLeft<elevationMiddle){
                start_row -= 1 ;
                start_col += 1;
                dist += elevationRight;
            }
            else{
                start_row -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_col < heightMap.at(start_row).size()-1 && stop && start_col != 0 && start_col != heightMap.at(start_row).size()-1){
        if (start_row == 0){
            stop = false;
            break;
        }
        int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
        int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
        int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
        if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
            start_row -= 1;
            start_col -= 1;
            dist += elevationLeft;
        }
        else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
            start_row -= 1;
            start_col += 1;
            dist += elevationRight;
        }
        else if (elevationRight==elevationLeft && elevationRight<elevationMiddle && elevationLeft<elevationMiddle){
            start_row -= 1 ;
            start_col += 1;
            dist += elevationRight;
        }
        else{
            start_row -= 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col==0){
            if (start_row == 0){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            int elevationRight = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col+1));
            if (elevationRight<elevationMiddle){
                start_row -= 1;
                start_col += 1;
                dist += elevationRight;
            }
            else{
                start_row -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
        while (start_col == heightMap.at(start_row).size()-1){
            if (start_row == 0){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col));
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row-1).at(start_col-1));
            if (elevationLeft<elevationMiddle){
                start_row -= 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else {
                start_row -= 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    //--------------------------------------------------------------------------------------------------
    //----------------------------------------SOUTH-----------------------------------------------------
    //--------------------------------------------------------------------------------------------------
    start_row = holderRow;
    start_col = holderCol;
    stop = true;
    while (start_col==0 && stop){
        if (start_row == heightMap.size()-1){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
        int elevationRight = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
        if (elevationRight<elevationMiddle){
            start_row += 1;
            start_col += 1;
            dist += elevationRight;
        }
        else{
            start_row += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col>0){
            if (start_row == heightMap.size()-1){
                stop = false;
                break;
            }
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
            int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
                start_row += 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
                start_row += 1;
                start_col += 1;
                dist += elevationLeft;
            }
            else if (elevationLeft==elevationRight && elevationLeft<elevationMiddle && elevationLeft<elevationMiddle){
                start_row += 1;
                start_col -= 1;
                dist += elevationRight;
            }
            else{
                start_row += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_col == heightMap.at(start_row).size()-1 && stop){
        if (start_row == heightMap.size()-1){
            stop = false;
            break;
        }
        int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
        int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
        if (elevationLeft<elevationMiddle){
            start_row += 1;
            start_col -= 1;
            dist += elevationLeft;
        }
        else {
            start_row += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col<heightMap.at(start_row).size()-1){
            if (start_row == heightMap.size()-1){
                stop = false;
                break;
            }
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
            int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
                start_row += 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
                start_row += 1;
                start_col += 1;
                dist += elevationRight;
            }
            else if (elevationRight==elevationLeft && elevationRight<elevationMiddle && elevationLeft<elevationMiddle){
                start_row += 1 ;
                start_col -= 1;
                dist += elevationRight;
            }
            else{
                start_row += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    while (start_col < heightMap.at(start_row).size()-1 && stop && start_col != 0 && start_col != heightMap.at(start_row).size()-1){
        if (start_row == heightMap.size()-1){
            stop = false;
            break;
        }
        int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
        int elevationMiddle=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
        int elevationRight=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
        if (elevationLeft<elevationMiddle && elevationLeft < elevationRight){
            start_row += 1;
            start_col -= 1;
            dist += elevationLeft;
        }
        else if (elevationRight<elevationMiddle && elevationRight < elevationLeft){
            start_row += 1;
            start_col += 1;
            dist += elevationRight;
        }
        else if (elevationRight==elevationLeft && elevationRight<elevationMiddle && elevationLeft<elevationMiddle){
            start_row += 1 ;
            start_col -= 1;
            dist += elevationRight;
        }
        else{
            start_row += 1;
            dist += elevationMiddle;
        }
        R.at(start_row).at(start_col)=color_r;
        G.at(start_row).at(start_col)=color_g;
        B.at(start_row).at(start_col)=color_b;
        while (start_col==0){
            if (start_row == heightMap.size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            int elevationRight = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col+1));
            if (elevationRight<elevationMiddle){
                start_row += 1;
                start_col += 1;
                dist += elevationRight;
            }
            else{
                start_row += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
        while (start_col == heightMap.at(start_row).size()-1){
            if (start_row == heightMap.size()-1){
                stop = false;
                break;
            }
            int elevationMiddle = fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col));
            int elevationLeft=fabs(heightMap.at(start_row).at(start_col)-heightMap.at(start_row+1).at(start_col-1));
            if (elevationLeft<elevationMiddle){
                start_row += 1;
                start_col -= 1;
                dist += elevationLeft;
            }
            else {
                start_row += 1;
                dist += elevationMiddle;
            }
            R.at(start_row).at(start_col)=color_r;
            G.at(start_row).at(start_col)=color_g;
            B.at(start_row).at(start_col)=color_b;
        }
    }
    return dist;
}

