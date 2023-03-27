class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> storage;
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++){
            int low = i+1;
            int high = n-1;
            while(low<high){
                if(nums[i] + nums[low] + nums[high]==0){
                    vector<int> curr = {nums[i] , nums[low] , nums[high]};
                    st.insert(curr);
                    low++;high--;
                }else if(nums[i] + nums[low] + nums[high]>0) high--;
                else low++;
            }
        }
        for(auto it : st) storage.push_back(it);
        return storage;
    }
};




// Optimal 

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int num1=nums[i];
            int tar = -num1;
            int lo = i+1,hi=n-1;
            while(lo<hi){
                int sum = nums[lo]+nums[hi];
                if(sum==tar){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                    
                    lo++;
                    hi--;
                }
                else if(sum<tar) lo++;
                else hi--;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};

*/
