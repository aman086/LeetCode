class Solution {
public:

    static bool cmp(pair<string , int> a , pair<string , int> b){
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        queue<int> q;
        q.push(id);
        unordered_map<int,bool> visited;
        visited[id] = true;
        int levl = 0;
        while(!q.empty()){
            levl++;
            // unordered_map<int,bool> visited;
            // visited[id] = true;
            int sz = q.size();
            for(int j=0;j<sz;j++){
                int currId = q.front();
                q.pop();
                for(int i=0;i<friends[currId].size();i++){
                    if(visited[friends[currId][i]]) continue;
                    visited[friends[currId][i]] = true;
                    q.push(friends[currId][i]);
                }
            }
            if(levl == level) break;
        }

        unordered_map<string,int> mp;
        
        while(!q.empty()){
            
            int ind = q.front();
            q.pop();
            // cout<<ind<<" ";
            for(int i=0;i<watchedVideos[ind].size();i++){
                mp[watchedVideos[ind][i]]++;
            }

        }
        // cout<<endl;
        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<endl;
        vector<pair<string , int>> vtr;
        for(auto it : mp){
            vtr.push_back({it.first , it.second});
        }

        sort(vtr.begin() , vtr.end() , cmp);
        vector<string> finalAns;
        for(auto it : vtr) finalAns.push_back(it.first);
        return finalAns;
    }
};
