/*
  The main idea where code is stuck is that
    we should make changes after all traversal completed
    because if you change in middle then values got affected
      
      suppose if you have value = 2
      and new color = 3
      and you do not have 4 adjacent same color node then you change 2 into 3
      but if any adjacent of your has 4 adjacent with same color,
      but after changes , when we go to that node and when it checks its adjacent , this node will not be
      counted because we change it , which makes wrong answer
      so , Instead
          we maintain vector<pair<int,int>> changes
          where we push all those x,y indices where change required
          after all traversal , we go to those places and make changes
*/
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int pixelValue = grid[row][col];
        if(pixelValue == color) return grid;

        queue<pair<int,int>> q;
        q.push({row,col});
        vector<vector<bool>> visited(grid.size() , vector<bool>(grid[0].size() , false));
        vector<pair<int,int>> changes;
        visited[row][col] = true;
        vector<int> x_values = {-1 , 0 , 1 , 0};
        vector<int> y_values = { 0 , 1 , 0 , -1};
        while(!q.empty()){
            pair<int,int> pr = q.front();
            q.pop();
            int x = pr.first;
            int y = pr.second;
            int cnt = 0;
            for(int i=0;i<4;i++){
                int x_ind = x + x_values[i];
                int y_ind = y + y_values[i];
                if(x_ind>=0 && x_ind<grid.size() && y_ind>=0 && y_ind<grid[0].size() && grid[x_ind][y_ind]==pixelValue){
                    cnt++;
                    if(visited[x_ind][y_ind]) continue;
                    q.push({x_ind , y_ind});
                    visited[x_ind][y_ind] = true;
                }
            }
            cout<<x<<" "<<y<<" "<<cnt<<endl;
            if(cnt!=4){
                changes.push_back({x,y});
            }
         }
         for(auto it : changes){
             grid[it.first][it.second]=color;
         }
         return grid;
    }
};
