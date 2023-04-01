/*
Here , we start from all 0
we first push them into queue and find if they had any adjacent 1
if yes then push them into queue
while all 1-distance one's pushed into queue then we again traversing queue and push all adjacent another 
one's into queue
and so on.

by this , one thing is sure that when we reach to any 1 then the distance is always minimal
because we are using BFS traversal
*/

class Solution {
public:

    bool valid(int i , int j , int n , int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    q.push({i , j});
            }
        }

        while(!q.empty()){
            
            int sz = q.size();
            
            for(int k=0;k<sz;k++){
                
                pair<int,int> pr = q.front();
                q.pop();
                int i = pr.first;
                int j = pr.second;
                int val = mat[i][j];
                if(valid(i-1 , j , n , m) && mat[i-1][j]==1){mat[i-1][j] = val-1; q.push({i-1 , j});}
                if(valid(i+1 , j, n , m) && mat[i+1][j]==1){mat[i+1][j] = val-1; q.push({i+1 , j});}
                if(valid(i , j-1, n , m) && mat[i][j-1]==1){mat[i][j-1] = val-1; q.push({i , j-1});}
                if(valid(i , j+1, n , m) && mat[i][j+1]==1){mat[i][j+1] = val-1; q.push({i , j+1});}
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]<0) mat[i][j]*=-1;
            }
        }
        return mat;
    }
};
