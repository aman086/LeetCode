class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0;
        unordered_map<long long , long long> mp;
        mp[0]++;
        int n = nums.size();
        int x = 0;
        for(int i=0;i<n;i++){
             x ^= nums[i];
            
            if(mp[x])
                ans+= mp[x];

            mp[x]++;    
        }
        return ans;
    }
};
