/*
  Here , in this question :
                      we simply make a array of all possible locations from where we pick up passenger or drop passenger then 
                      Initialize all values to zero in starting
                      then go to each vector(NumberOfPassenger , pickUp , dropUp)
                      and since we are picking up NumberOfPassenger from pickUp so we add  NumberOfPassenger to pickUp index till dropUp Index
                      and after reaching dropUp , we substract NumberOfPassenger from dropUp index
                      and take a prefix sum
                      because 
                      NumberOfPassenger are travelling from pickUp to dropUp, after dropUp point they'll remove
                      and check if at any point our prefix sum is greater than capacity then return false;
                      and also check for 0-Index because inside loop,we are checking from Index-1
                      so we explicitly check for Index-0.
                      if condition fails then return false;
                      otherwise at last return true;
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector<int> places(1001 , 0);
         int n = trips.size();
         for(int i=0;i<n;i++){
             places[trips[i][1]]+=trips[i][0];
              places[trips[i][2]]-=trips[i][0];
         }
         if(places[0]>capacity) return false;
         for(int i=1;i<1001;i++){
             places[i] += places[i-1];
             if(places[i]>capacity) return false;
         }
         return true;
    }
};
