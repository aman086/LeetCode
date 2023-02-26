class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> result;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }
            result.emplace(cnt , i);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(result.top().second);
            result.pop();
        }
        return ans;
    }
};
