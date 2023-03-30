class Solution {
public:

    // bool checkOneTransition(string a , string b){
        
    //     int differ = 0;
        
    //     for(int i=0;i<a.size();i++){
    //         if(a[i]!=b[i]) differ++;
    //         if(differ>1) return false;
    //     }

    //     return true;
    // }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         int n = wordList.size();

         unordered_map<string , bool> visited,mp;
         
         for(auto it : wordList) mp[it]=1;
         if(mp[endWord]==0) return 0;

         queue<pair<string,int>> q;
         q.push({beginWord , 1});
         visited[beginWord] = true;
         
         while(!q.empty()){
             int sz = q.size();
            
             for(int i=0;i<sz;i++){
            
                 pair<string,int> pr = q.front();
                 q.pop();
            
                 string current = pr.first;
                 int count = pr.second;
                 if(current == endWord) {return count;}
                
                for(int i=0;i<current.size();i++){
                    for(char c='a';c<='z';c++){
                      string cur = current;
                      cur[i] = c;
                      if(!visited[cur] && mp[cur]){
                          q.push({cur , count+1});
                          visited[cur] = true;
                      }
                     }
                }
             }
         }
         return 0;
    }
};
