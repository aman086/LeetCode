/*

Here, we first store count and index of every integer in unordered_map < int , pair<int,int>> mp;
then , 
  Since , I need 2 values which sum is equal to any power of 2 ;
  I took first integer and apply a for loop for 22 times , because constraint is equal to = 2^20;
    then for every Integer , I substract it from - 1,2,4,8,16,32,64,128,256,512,1024,2048,4096........so on
  and continuously doing this with checking in our map (mp).
      suppose , our current Integer is 3 so , I need 1 for becoming sum = 4.
        so I search 1 in map .....if(mp[1]>0) because in map I also store count.
        similary doing this for greater number too..... 
        for 8 , I need 5
        for 16 , I need 13
        
        and also I have to check that If the element that I am searching , should be present in after that element , otherwise we did not take it. 
*/

class Solution {
public:
    int M = 1e9+7;
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, pair<int , int>> mp;
        int n = deliciousness.size();
        sort(deliciousness.begin() , deliciousness.end());
        for(int i=0;i<n;i++){
            mp[deliciousness[i]] = {i , ++mp[deliciousness[i]].second};
        }
        // for(auto it : mp)
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(i>0 && deliciousness[i]==deliciousness[i-1]) continue;
            long long int curr = deliciousness[i];
            long long int val = 1;
            for(int j=1;j<23;j++){
                long long int needed = val - curr;
                // cout<<curr<< " "<<val<<" "<<needed<<" "<<cnt<<endl;
                val <<= 1;
                if(curr > needed) continue;
                if(mp[needed].second==0) continue;
                if(mp[needed].first < i) continue;
                if(curr == needed){
                    int m = mp[needed].second - 1;
                    if(m > 0){
                        cnt = (cnt + (m * 1ll * (m+1)/2)%M)%M;
                    }
                }else{
                    cnt = (cnt + (mp[needed].second * 1ll * mp[curr].second)%M)%M;
                }
            }
        }
        return (int)cnt;

    }
};
