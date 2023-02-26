class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        int current = num;
        int cnt=0;
        while(current!=0){
            int rem = current%10;
            cnt++;
            if(rem&1){
                odd.push(rem);
//                 cout<<"Odd : "<<rem<<endl;
            }
            else{
                even.push(rem);
//                 cout<<"Even : "<<rem<<endl;
            }

            current/=10;        
        }
        // cnt--;
//         cout<<cnt<<endl;
        current = num;
        int finalResult=0;
        int number = pow(10 , cnt-1);
        while(cnt--){
            int vl = current/number;
            if(vl&1){
                finalResult = finalResult * 10 + odd.top();
                odd.pop();
            }else{
                finalResult = finalResult * 10 + even.top();
                even.pop();
            }
            current%=number;
            number/=10;
        }
        return finalResult;

    }
};
