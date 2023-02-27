class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int , vector<int> , greater<int>> result;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                result.push(matrix[i][j]);
        }
        k--;
        while(k--){
            result.pop();
        }
        return result.top();
    }
};
