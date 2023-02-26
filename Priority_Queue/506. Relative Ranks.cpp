class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> result;
        for(int i=0;i<score.size();i++){
            result.emplace(score[i] , i);
        }
        vector<string> finalAns(score.size());
        int cnt=0;
        while(!result.empty()){
            cnt++;
            pair<int,int> curr = result.top();
            result.pop();
            if(cnt==1)
             finalAns[curr.second] = "Gold Medal";
            else if(cnt==2)
             finalAns[curr.second] = "Silver Medal";
            else if(cnt==3)
             finalAns[curr.second] = "Bronze Medal";
            else
             finalAns[curr.second] = to_string(cnt);
        }
        return finalAns;
    }
};
