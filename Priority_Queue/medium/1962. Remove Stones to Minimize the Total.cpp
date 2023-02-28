class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> result;
        int n = piles.size();
        for(int i=0;i<n;i++){
            result.push(piles[i]);
        }
        while(k--){
            int topEle = result.top();
            result.pop();
            topEle = ((topEle%2==0)?topEle/2:topEle/2+1);
            result.push(topEle);
        }
        int sum = 0;
        while(!result.empty()){
            sum += result.top();
            result.pop();
        }

        return sum;
    }
};
