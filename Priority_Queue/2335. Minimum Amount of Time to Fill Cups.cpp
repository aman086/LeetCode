class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n = amount.size();
        priority_queue<int> result;
        for(auto i : amount) {
            if(i!=0) result.push(i);
        }
        int fir, sec;
        int sm = 0;
        while(!result.empty()){
            sm++;
            int fir = result.top();
            result.pop();
            sec = 0;
            if(!result.empty()){
                sec = result.top();
                result.pop();
            }
            if(fir-1>0)
            result.push(fir-1);
            if(sec-1>0)
            result.push(sec-1);
        }
        return sm;
    }
};
