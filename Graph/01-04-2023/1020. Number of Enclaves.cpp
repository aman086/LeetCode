class Solution {
public:

    bool valid(int i , int j , int n , int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) { grid[i][0] = 0 ;q.push({i , 0});}
            if(grid[i][m-1]==1) { grid[i][m-1] = 0; q.push({i , m-1});}
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) { grid[0][i] = 0; q.push({0 , i});}
            if(grid[n-1][i]==1) { grid[n-1][i] = 0; q.push({n-1 , i});}
        }

        while(!q.empty()){
            
                pair<int,int> pr = q.front();
                q.pop();
                
                int i = pr.first;
                int j = pr.second;

                if(valid(i-1 , j , n , m) && grid[i-1][j]==1){grid[i-1][j] = 0; q.push({i-1 , j});}
                if(valid(i+1 , j, n , m) && grid[i+1][j]==1){grid[i+1][j] = 0; q.push({i+1 , j});}
                if(valid(i , j-1, n , m) && grid[i][j-1]==1){grid[i][j-1] = 0; q.push({i , j-1});}
                if(valid(i , j+1, n , m) && grid[i][j+1]==1){grid[i][j+1] = 0; q.push({i , j+1});}

        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};
