
#ifndef mountain_h
#define mountain_h
#include <vector>
#include <cmath>
using namespace std;
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G, vector<vector<int>>& B, int color_r, int color_g,int color_b, int start_row);
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& R, vector<vector<int>>& G,
              vector<vector<int>>& B, int color_r, int color_g, int color_b,
              int start_row, int start_col);
#endif
