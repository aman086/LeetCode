/*
But , this is not the optimal one because there is one algorithm named -- Quick Select 
which can solve this problem in O(n) time complexity.
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> result;
        for(auto i : nums) result.push(i);
        k--;
        while(k--) result.pop();
        return result.top();
    }
};
