class Solution {
public:

    bool dfs(int i , bool f , unordered_set<int>& first , unordered_set<int>& second , vector<bool>& visited , vector<vector<int>>& graph){

        // cout<<i<<" "<<f<<endl;
        for(auto it : graph[i]){

                    if(f) {
                        if(second.find(it)!=second.end()) return false;
                        if(visited[it]) continue;
                        first.insert(it);
                        // f = !f;
                        visited[it] = true;
                        if(dfs(it , !f , first , second , visited , graph)==false) return false;
                    }else{
                        if(first.find(it)!=first.end()) return false;
                        if(visited[it]) continue;
                        second.insert(it); 
                        // f = !f;
                        visited[it] = true;
                        // cout<<dfs(it , !f , first , second , visited , graph)<<" "<<it<<endl;
                        if(dfs(it , !f , first , second , visited , graph)==false) return false;
                    }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        unordered_set<int> first;
        unordered_set<int> second;
        
        bool f = false;
        
        int n = graph.size();
        
        if(n==1) return true;
      
        vector<bool> visited(n , false);
        for(int i=0;i<n;i++){
            if(graph[i].size()>0 && !visited[i]){
                // q.push(i);
                visited[i] = true;
                first.insert(i);
                if(dfs(i , f , first , second , visited , graph)==false) return false;
            }
        }
    //    cout<<endl;  
    //     for(auto it : first) cout<<it<<" ";
    //      cout<<endl;
    //     for(auto it : second) cout<<it<<" ";
    //      cout<<endl;

        return true;
        
        // while(!q.empty()){
            
        //     int sz = q.size();
        //     for(int j = 0; j<sz; j++){
                
        //         int tp = q.front();
        //         q.pop();
                
        //         for(auto it : graph[tp]){

        //             if(f) {
        //                 if(second.find(it)!=second.end()) return false;
        //                 if(visited[it]) continue;
        //                 first.insert(it);
        //                 q.push(it);
        //                 visited[it] = true;
        //             }else{
        //                 if(first.find(it)!=first.end()) return false;
        //                 if(visited[it]) continue;
        //                 second.insert(it); 
        //                 q.push(it);
        //                 visited[it] = true;
        //             }
        //         }
        //     }

        //     f = !f;
        // }

        // for(auto it : first) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : second) cout<<it<<" ";
        // cout<<endl;
        // return true;
    }
};
