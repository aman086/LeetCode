//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void bfs(vector<vector<int>>& adj , vector<bool>& visited , int vertex){
        queue<int> q;
        q.push(vertex);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr] == true) continue;
            visited[curr] = true;
            for(auto it : adj[curr]){
                q.push(it);
            }
        }
    }
    int numProvinces(vector<vector<int>> a, int v) {
        vector<bool> visited(v+1 , false);
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(a[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<v;i++){
            if(visited[i] == false){
                cnt++;
                bfs(adj , visited , i);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
