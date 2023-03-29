/*
Idea is very simple.
  If you have 2 sides of water means that you have 2 sides which untouched by any land so we count them
  and also if you are at the border of grid then your those sides which are border of grid will also be counted because
  they also not touched by any other land
  
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row_vl = {-1 , 0 , 1 , 0};
        vector<int> col_vl = {0 , -1 , 0 , 1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int x_ind = i + row_vl[k];
                        int y_ind = j + col_vl[k];
                        if(x_ind<0 || x_ind>=n || y_ind<0 || y_ind>=m){cnt++; continue;}
                        if(grid[x_ind][y_ind]==0) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
