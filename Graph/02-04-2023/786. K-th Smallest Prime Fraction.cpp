class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float , pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({arr[i]*1.0/arr[j] , {arr[i] , arr[j]}});
            }
        }
        k = pq.size()-k+1;
        while(!pq.empty()){
            k--;
            if(k==0) return {pq.top().second.first , pq.top().second.second};
            pq.pop();
        }
        return {-1 , -1};
    }
};
