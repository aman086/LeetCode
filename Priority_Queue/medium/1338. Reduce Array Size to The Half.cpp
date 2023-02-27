class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> result;
        int n = arr.size();
        unordered_map<int,int> calculateCount;
        for(int i=0;i<n;i++){
            calculateCount[arr[i]]++;
        }
        for(auto it : calculateCount){
            result.emplace(it.second , it.first);
        }
        int currEle = 0;
        int cnt=0;
        while(!result.empty()){
            pair<int,int> curr = result.top();
            result.pop();
            cnt++;
            currEle += curr.first;
            if(currEle >= (n/2))
             break;
        }
        return cnt;
    }
};
