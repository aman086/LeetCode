class Solution {
public:

    bool valid(int n , int m , int i , int j){
        if(i>=n || i<0) return false;
        if(j>=m || j<0) return false;
        // if(i==parent_i && j==parent_j) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
         pq.push({ 0 , {0 , 0} });
        int n = heights.size();
        int m = heights[0].size();

        // int finalAns = INT_MAX;
        vector<vector<int>> dis(n , vector<int>(m , 12345678));
         dis[0][0] = 0;
         while(!pq.empty()){
             auto it = pq.top();
             pq.pop();
             int prevDiff = it.first;
             int i = it.second.first;
             int j = it.second.second;
             int prevEle = heights[i][j];
             cout<<prevEle<<" "<<prevDiff<<endl;
             if(i==n-1 && j==m-1){
                 return prevDiff;
             }
             if(valid(n , m , i , j-1)){
                 int diff = max(prevDiff , abs(prevEle - heights[i][j-1]));
                 if(diff < dis[i][j-1]){
                     dis[i][j-1] = diff;
                     pq.push({diff , {i , j-1}});
                 }
             }
             if(valid(n , m , i , j+1)){
                 int diff = max(prevDiff , abs(prevEle - heights[i][j+1]));
                 if(diff < dis[i][j+1]){
                     dis[i][j+1] = diff;
                     pq.push({diff , {i , j+1}});
                 }
             }
             if(valid(n , m , i+1 , j)){
                int diff = max(prevDiff , abs(prevEle - heights[i+1][j]));
                if(diff < dis[i+1][j]){
                     dis[i+1][j] = diff;
                     pq.push({diff , {i+1 , j}});
                 }
             }
             if(valid(n , m , i-1 , j)){
                 int diff = max(prevDiff , abs(prevEle - heights[i-1][j]));
                 if(diff < dis[i-1][j]){
                     dis[i-1][j] = diff;
                     pq.push({diff , {i-1 , j}});
                 }
             }
         }
         return 0;
    }
};
