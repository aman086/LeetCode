class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int finalAns = 0;
        int n = capacity.size();
         vector<int> currRockNeeded(n);
        for(int i=0;i<n;i++)
            currRockNeeded[i] = capacity[i] - rocks[i];
        
        sort(currRockNeeded.begin() , currRockNeeded.end());
        int cnt=0;
        for(auto it : currRockNeeded){
            if(additionalRocks >= it){
                cnt++;
                additionalRocks -= it;
            }
        }
        return cnt;
    }
};
