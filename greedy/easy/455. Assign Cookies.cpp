class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int i = 0 , j = 0;
        int g_size = g.size();
        int s_size = s.size();
        int cnt=0;
        while(i<g_size && j<s_size){
            if(s[j]>=g[i]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};
