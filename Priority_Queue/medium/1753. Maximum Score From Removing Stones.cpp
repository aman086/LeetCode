class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> result;
        result.push(a);
        result.push(b);
        result.push(c);
        int cnt=0;
        while(result.size()>1){
            int fir = result.top();
            fir--;
            result.pop();
            int sec = result.top();
            sec--;
            result.pop();
            cnt++;
            if(fir!=0) result.push(fir);
            if(sec!=0) result.push(sec);
        }
        return cnt;
    }
};
