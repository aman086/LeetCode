class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       
      // Approach___1 (using priority queue)
      
      priority_queue<int , vector<int> , greater<int>> result;
        for(auto it : nums) result.push(it);
        int k=0;
        while(!result.empty()){
            nums[k] = result.top();
            result.pop();
            k++;
        }
        return nums;
      
      
      
      // Approach___2 (counting sort)
      
      
      
        int n = nums.size();
        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());
        int sz = maxi - mini + 1;
        vector<int> count(sz , 0);
        for(int i=0;i<n;i++){
            count[nums[i] - mini]++;
        }

        for(int i=1;i<sz;i++){
            count[i] += count[i-1];
        }

        vector<int> output(n);
        for(int i=n-1;i>=0;i--){
            output[count[nums[i] - mini]-1] = nums[i];
            count[nums[i]-mini]--;
        }
        for(int i=0;i<n;i++) nums[i] = output[i];
        return nums;
    }
};
