/*
Here , we have to think in 2 things:
  1.  choose next smallest available value and its index
  2.  calculate distance from current point to that index
  
     do this on and on until we not finished all values
     and then return their totalDistance summation
*/


#define p pair<int,pair<int,int>>

class Solution {
public:

    vector<int> dr = {-1 , 0 , 1 , 0};
    vector<int> dc = {0 , -1 , 0 , 1};

    int calculateDistance(int i , int j , int u , int v , vector<vector<int>>& forest){

        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<bool>> visited(forest.size() , vector<bool>(forest[0].size() , false));
        bool found = false;
        int cnt = 0;
        while(!q.empty()){

            int sz = q.size();
            for(int i=0;i<sz;i++)
            {auto tp = q.front();
            q.pop();
            
            if(tp.first == u && tp.second == v) {found = true; break;}
            for(int i=0;i<4;i++){
                
                int x = tp.first + dr[i];
                int y = tp.second + dc[i];

                if(x<0 || x>=forest.size() || y<0 || y>=forest[0].size()) continue;
                if(forest[x][y]!=0 && !visited[x][y]){
                    visited[x][y] = true;
                    q.push({x , y});
                }
            }}
            if(found) break;
            cnt++;
        }

        return (found==true)?cnt:-1;
    }


    int cutOffTree(vector<vector<int>>& forest) {
        
        int n = forest.size();
        int m = forest[0].size();

        priority_queue<p , vector<p> , greater<p>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1) pq.push({forest[i][j] , {i , j}});
            }
        }

        int i = 0 , j = 0;
        int totalDistance = 0;
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int u = tp.second.first;
            int v = tp.second.second;
            int dist = calculateDistance(i , j , u , v , forest);
            if(dist==-1){
                return -1;
            }

            totalDistance += dist;


            i = u;
            j = v;

        }

        return totalDistance;
    }
};
