class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> result;
        int n = points.size();
        for(auto it : points){
            int fir = it[0];
            int sec = it[1];
            result.push({fir*fir + sec*sec , {fir , sec}});
            if(result.size()>k)
             result.pop();
        }
        vector<vector<int>> finalAns(k);
        int m=0;
        while(!result.empty()){
            pair<int,pair<int,int>> current = result.top();
            result.pop();
            finalAns[m].push_back(current.second.first);
            finalAns[m].push_back(current.second.second);
            m++;
        }
        return finalAns;
    }
};
