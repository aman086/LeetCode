class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> finalArr;
        if(num==0) return {-1 , 0 , 1};
        if(num%3!=0) return finalArr;

        if(num%3==0){
            finalArr.push_back(num/3-1);
            finalArr.push_back(num/3);
            finalArr.push_back(num/3+1);
        } 
        return finalArr;
    }
};
