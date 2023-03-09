class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if(label == 1) return {1};
        vector<int> result;
        int n = label;
        int cnt = 1;
        int start = 1;
/*
    In below code , 
        we are checking it the level of target node is even or odd...
        if it is even then no change
        but if it is odd then convert it accordingly
        means , 
            Instead of label , we put an element whose distance from end is same as
            distance of label from start;
*/
        while(true){
            start <<= 1;
            int last = 2*start - 1;
            if(n <= last){
                if(cnt & 1){
                    // int diff_start = n - start;
                    // n = last - (diff_start);
                    n = last - (n - start);
                }else{}
                break;
            }
            cnt++;
        }
    
    /* Here , In this line , we add path from the current target node to the 1 (root)
        eg: for 14 =>
            14 
            14/2 = 7;
            7/2 = 3;
            3/2 = 1;
            path = 14-7-3-1

        eg: for 26 =>
            26
            26/2 = 13;
            13/2 = 6;
            6/2 = 3;
            3/2 = 1;
            path = 26-13-6-3-1    
    */
        while(n > 0){
            result.push_back(n);
            n/=2;
        }
/*
    Since , we added our data into reverse manner , so reverse it and 
    find our accurate path.
    for 14 = 14-7-3-1;
    so , we change it : 1-3-7-14
    for better traversing.
*/        
        reverse(result.begin() , result.end());
        int sz = result.size();
        for(int i=0;i<sz;i++){
            if(i & 1){ // odd
                 // int st = (1 << i);
                // int ls = 2*st - 1;
                // int dif = result[i] - st;
                // result[i] = ls - dif;
                result[i] = (2*(1<<i) - 1) - (result[i] - (1 << i));
            }else{  // even

            }
        }
        return result;
    }
};
