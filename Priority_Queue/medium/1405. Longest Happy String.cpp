/*
 Main logic here is that :
      we have to select 2 maximum occurrence character;
      firstly , we select top occurence element and reduce its size according to the character , we use
       if we choose 1 char then substract count by 1
       if we choose 2 char then substract count by 2
       
       now , go on the second top element (we can go to the second one by popping the first one)
       and check whether the second element count is less than to first one ( after substraction ) or greater than.
       and according to that add that char and decrease count of that element too according to the condition(decrease by 1 / decrease by 2)..
       and do the same operation again and again...
      and also check if at any point there is remaining only one char then after adding that char , we break the loop
      eg:
        If we have only 'c' , whose count = 6. and no other char present then I add 2 c's to my string and break the loop.
        
       
*/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>> result;
        if(a!=0) result.emplace(a , 'a');
        if(b!=0) result.emplace(b , 'b');
        if(c!=0) result.emplace(c , 'c');
        string finalStr="";
        while(!result.empty()){
            pair<int,int> fir = result.top();
            result.pop();
            if(fir.first>1){
                fir.first-=2;
                finalStr.push_back(fir.second);
                finalStr.push_back(fir.second);
            }else{
                fir.first-=1;
                finalStr.push_back(fir.second);
            }
            if(result.size()==0) break;
            if(result.size()>0){
                pair<int,int> sec = result.top();
                result.pop();
                if(sec.first<fir.first){
                    sec.first-=1;
                    finalStr.push_back(sec.second);
                }else{
                    if(sec.first>1){
                        sec.first-=2;
                        finalStr.push_back(sec.second);
                        finalStr.push_back(sec.second);
                    }else{
                        sec.first-=1;
                        finalStr.push_back(sec.second);
                    }
                }
                if(sec.first>0) result.emplace(sec.first , sec.second);
            }
            if(fir.first>0) result.emplace(fir.first , fir.second);
                // if(sec.second>0) result.emplace(sec.second , sec.first);
        }
        return finalStr;
    }
};
