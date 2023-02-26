class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       /*
       unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                st.insert(nums[i]);
        }
        return st.size();
      */
        priority_queue<int,vector<int> , greater<int>> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                result.push(nums[i]);
        }
        int cnt=0;
        while(!result.empty()){
            cnt++;
            int first = result.top();
            result.pop();
            vector<int> curr;
            while(!result.empty()){
                int current = result.top();
                result.pop();
                curr.push_back(current-first);
            }
            for(auto it : curr) cout<<it<<" ";
            cout<<endl;
            for(int i=0;i<curr.size();i++){
                if(curr[i]!=0) result.push(curr[i]);
            }
        }
        return cnt;
    }
};
