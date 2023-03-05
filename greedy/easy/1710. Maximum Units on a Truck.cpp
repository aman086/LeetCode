class Solution {
public:

    // bool static cmp(vector<int> a , vector<int> b){
    //     return a[1]>b[1];
    // }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         int n = boxTypes.size();
        //  sort(boxTypes.begin() , boxTypes.end() , cmp);
        sort(begin(boxTypes), end(boxTypes), [](auto &a, auto &b){return a[1] > b[1];});
         int finalResult=0;
         for(int i=0;i<n;i++){
             if(truckSize == 0) return finalResult;
             if(boxTypes[i][0] <= truckSize){
                 finalResult += (boxTypes[i][1] * boxTypes[i][0]);
                 truckSize -= boxTypes[i][0]  ;
             }else{
                 finalResult += (boxTypes[i][1] * truckSize);
                 truckSize = 0;
             }
         }
         return finalResult;
    }
};
//     class Solution {
// public:
//     int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
//         // support variables
//         int res = 0, currBatch;
//         // sorting boxes by decreasing capacity
//         sort(begin(boxes), end(boxes), [](auto &a, auto &b){return a[1] > b[1];});
// 		// carrying as many larger sized boxes as we can first
//         for (auto &el: boxes) {
//             currBatch = min(el[0], truckSize);
//             truckSize -= currBatch;
//             res += currBatch * el[1];
//             if (!truckSize) break;
//         }
//         return res;
//     }
// };
