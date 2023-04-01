class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> diff(n , vector<int>(m , 0));
        vector<int> rowInserted(n , 0);
        vector<int> colInserted(m , 0);
        
        for(int i=0;i<n;i++){
            
            int valToBeInserted = 0;
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) valToBeInserted+=1;
                else valToBeInserted-=1;
            }
            
            rowInserted[i] = valToBeInserted;
        }


        for(int i=0;i<m;i++){
            
            int valToBeInserted = 0;
            
            for(int j=0;j<n;j++){
                if(grid[j][i]==1) valToBeInserted+=1;
                else valToBeInserted-=1;
            }
            
            colInserted[i] = valToBeInserted;
        }

        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                diff[i][j] += rowInserted[i];
                diff[i][j] += colInserted[j];
            }

        }
        return diff;
    }
};
