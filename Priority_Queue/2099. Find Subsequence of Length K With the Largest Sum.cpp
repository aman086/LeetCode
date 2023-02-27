class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> result;
        for(int i=0;i<nums.size();i++){
            result.emplace(nums[i] , i);
            if(result.size()>k){
                result.pop();
            }
        }
        map<int,int> mp;
        while(!result.empty()){
            pair<int,int> curr = result.top();
            result.pop();
            mp[curr.second] = curr.first;
        }
        vector<int> finalAns;
        for(auto it : mp){
            finalAns.push_back(it.second);
        }
        return finalAns;
    }
};
