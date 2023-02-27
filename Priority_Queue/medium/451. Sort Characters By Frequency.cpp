class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char , int> alphaCount;
        for(int i=0;i<n;i++){
            alphaCount[s[i]]++;
        }
        priority_queue<pair<int , char>> finalAns;
        for(auto it : alphaCount)
            finalAns.emplace(it.second ,it.first);
        string finalString = "";
        while(!finalAns.empty()){
            pair<int , char> current = finalAns.top();
            finalAns.pop();
            while(current.first--)
                finalString.push_back(current.second);
        }    
        return finalString;
    }
};
