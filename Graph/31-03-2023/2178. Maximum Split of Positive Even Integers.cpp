class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
         
         if(finalSum&1) return {}; // Odd
         vector<long long> ans;
         long long sm = 0;
         long long currNo = 2;
         while(true){
            sm += currNo;
            if(finalSum - sm <= currNo){
                sm-=currNo;
                currNo-=2;
                break;
            }
            if(finalSum == sm){return ans;}
            ans.push_back(currNo);
            currNo+=2;
         }

         ans.push_back(finalSum - sm);
         return ans;
    }
};
