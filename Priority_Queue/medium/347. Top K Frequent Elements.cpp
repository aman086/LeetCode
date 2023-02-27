class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>> result;
        for(auto it : mp)
            result.emplace(it.second , it.first); 
            vector<int> finalAns;
        while(k--){
            pair<int,int> current = result.top();
            result.pop();
            finalAns.push_back(current.second);
        }     
        return finalAns;
    }
};
