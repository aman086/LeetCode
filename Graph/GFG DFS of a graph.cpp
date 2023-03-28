//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> finalAnswer;
    void dfs(int node , vector<int> adj[] , vector<bool>& visited){
        
        for(auto vl : adj[node]){
            if(visited[vl]) continue;
            visited[vl]=true;
            finalAnswer.push_back(vl);
            dfs(vl , adj , visited);
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<bool> visited(v+1 , false);
        finalAnswer.push_back(0);
        visited[0] = true;
        dfs(0 , adj , visited);
        return finalAnswer;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
