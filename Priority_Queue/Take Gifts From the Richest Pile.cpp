class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> result(gifts.begin() , gifts.end());
        while(k--){
            int top = result.top();
            result.pop();
            result.push(sqrt(top));
        }
        long long sum =0;
        while(!result.empty()){
            int curret = result.top();
            result.pop();
            sum += curret;
        }
        return sum;
    }
};
