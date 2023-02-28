/*

Main logic here is that:
    we have to give maximum no to that city who is connected with more no of cities so that this city contribute more sum
    and similarly decreasing assignment according to the count of cities connected with other cities

*/

class Solution {
public:
    long long maximumImportance(int m, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>> result;
        int n = roads.size();
        unordered_map<int,int> hsh;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                hsh[roads[i][j]]++;
            }
        }
        for(auto it : hsh){
            result.emplace(it.second , it.first);
        }

        long long int sum = 0,curr=m;
        while(!result.empty()){
            pair<int,int> topEle = result.top();
            result.pop();
            sum += (topEle.first *1ll * curr);
            curr--;
        }

        return sum;
    }
};
