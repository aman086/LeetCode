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



// Binary Search Approach

class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                count+= upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin();
            }
            if(count < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};
