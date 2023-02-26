class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> result(stones.begin() , stones.end());
        int n = stones.size();
        while(result.size()>1){
            int first = result.top();
            result.pop();
            int second = result.top();
            result.pop();
            if(first != second) result.push(abs(first-second));
        }
        if(result.size()==1) return result.top();
        return 0;
    }
};
