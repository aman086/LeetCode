#define PI pair<int,int>
class Solution {
public:

// This below code for priority queue
// Here , we are making our own container which stores value in descending manner of second element in pair   
 class Compare {
        public:
            bool operator()(PI below, PI above)
            {
                return below.second < above.second;
            }
    };

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        int n = barcodes.size();
        vector<int> result(n);
        
        priority_queue<PI , vector<PI> , Compare> pq;
        unordered_map<int,int> mp;
        for(int vl : barcodes) mp[vl]++;

        for(auto it : mp) pq.push({it.first , it.second});

        int currIndex = 0;
        while(!pq.empty()){
            
            auto tp = pq.top();
            pq.pop();

            int no = tp.first;
            int cnt = tp.second;

            if(pq.size()==0){result[currIndex] = no; break;}

            auto tp_ = pq.top();
            pq.pop();
            int no_ = tp_.first;
            int cnt_ = tp_.second;

            if(currIndex == 0){
                result[0] = no;
                result[1] = no_;
            }else{
                if(result[currIndex-1]!=no){
                    result[currIndex] = no;
                    result[currIndex+1] = no_;
                }else{
                    result[currIndex] = no_;
                    result[currIndex+1] = no;
                }
            }
            currIndex+=2;
            if(cnt-1 > 0)
            pq.push({no , cnt - 1});
            if(cnt_ - 1 > 0)
            pq.push({no_ , cnt_ - 1});
            
        }
        return result;
        
    }
};
