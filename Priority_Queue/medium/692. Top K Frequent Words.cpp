/*
We have to use comparator class for sorting in such a way , question demands
So, I requires knowledge about how to apply comparator on priority_queue;

*/
class Solution {
public:
   class cmp{
       public:
        bool operator()(pair<int,string> a , pair<int,string> b){
                if(a.first < b.first) return true;
                else if(a.first==b.first) return a>b;
                return false;
        }
   };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string> , vector<pair<int, string>> , cmp> result;
        int n = words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[words[i]]++;

        for(auto it : mp)
            result.emplace(it.second , it.first);
        vector<string> vtr;
        while(k--){
            vtr.push_back(result.top().second);
            result.pop();
        }
        return vtr;
    }
};
