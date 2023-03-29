class Solution {
public:
    vector<int> dr = {-1 , 0 , 1 , 0};
    vector<int> dc = {0 , -1 , 0 , 1};
    
    void dfs(int r , int c , int n , int m , vector<vector<char>>& grid){
            
            for(int i=0;i<4;i++){
                int x = r + dr[i];
                int y = c + dc[i];

                if(x<0 || x>=n || y<0 || y>=m) continue;

                if(grid[x][y]=='1'){
                    grid[x][y] = '0';
                    dfs(x , y , n , m , grid);
                }
            }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    grid[i][j] = '0';
                    dfs(i , j , n , m , grid);
                }
            }
        }
        return cnt;
    }
};
