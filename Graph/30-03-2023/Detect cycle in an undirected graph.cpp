//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node , int parent , vector<bool>& visited , vector<int> adj[]){
        
        for(int it : adj[node]){
            if(it==parent) continue;
            if(visited[it]) return true;
            visited[it] = true;
            if(dfs(it , node , visited , adj)) return true;
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> visited(v+1 , false);
        for(int i=0;i<v;i++){
            if(visited[i]) continue;
            visited[i] = true;
            if(dfs(i , -1 , visited , adj)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
