class Solution {
public:

    void bfs(int node , vector<vector<int>>& adj , vector<bool>& visited){

        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr]) continue;
            visited[curr] = true;
            for(int vl : adj[curr]){
                if(visited[vl]) continue;
                q.push(vl);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> visited(v , false);
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                cnt++;
                bfs(i , adj , visited);
            }
        }
        return cnt;
    }
};
