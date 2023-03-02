/*
  We simply , want to make groups of size = groupSize and elements should be in consecutive manner
  So , everytime we work only on top groupSize element and substract first element count from all of
  them , because If first one occurs 4 times then its all consecutive should be occured atleast 4 times 
  and can also occur more than 4 times.
  and after these iteration , at every time 
   we store elements in a vector that we popped from queue. and again if there count is >= 0
    then again push them with their new count
    and if at any point , count of a no is < 0 means that , It is not available in all places where group's first element 
    present , then also we return false
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto it : hand)
            mp[it]++;
        for(auto vl : mp){
            // if(vl.second > groupSize) return false;
            pq.emplace(vl.first , vl.second);
        }  
        
        while(!pq.empty()){
            if(pq.size() < groupSize) return false;
            int k = groupSize;
            int subs = pq.top().second;
            int firstEle = pq.top().first-1;
            vector<pair<int,int>> reserve;
            while(k--){
                auto curr = pq.top();
                pq.pop();
                if(curr.first-firstEle !=1) return false;
                curr.second -= subs;
                if(curr.second<0) return false;
                if(curr.second!=0) reserve.push_back({curr.first,curr.second});
                firstEle = curr.first;
            }

            for(auto it : reserve){
                cout<<it.first<<" "<<it.second<<endl;
                pq.emplace(it.first , it.second);
            }
            cout<<endl<<endl;
        }
        return true;
    }
};
