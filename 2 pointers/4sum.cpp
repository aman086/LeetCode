class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();
        vector<vector<int>> storage;
        if(n<4) return storage;
        sort(nums.begin() , nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            long int req_i = target - nums[i];
            for(int j=i+1;j<n-2;j++){
                if(j>(i+1) && nums[j]==nums[j-1]) continue;
                long int req_j = req_i - nums[j];
                int low = j+1;
                int high = n-1;
                while(low<high){
                    long int sm = nums[low] + nums[high];
                    if(sm == req_j){
                        storage.push_back({nums[i] , nums[j] , nums[low] , nums[high]});
                        int tmp_1 = nums[low]; int tmp_2 = nums[high];
                        while(low<n && nums[low]==tmp_1) low++;
                        while(high>=0 && nums[high]==tmp_2)high--;
                    }else if(sm > req_j) high--;
                    else low++;
                }
            }
        }
        return storage;
    }
};
