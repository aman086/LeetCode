class Solution {
public:

    string sum(string a , string b){
        int i = a.size()-1;
        int j = b.size()-1;
        // int i=n1-1,j=n2-1;
        long int carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry!=0){
            int first = (i>=0 ? a[i]:'0')-'0';
            int second = (j>=0 ? b[j]:'0')-'0';

            long int sm = first + second + carry;
            carry = (sm/10);
            ans.push_back((sm%10)+'0');
            i--;
            j--;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }

    string product(string a , char b){
        string result="";
        // int n = a.size();
        int i=a.size()-1;
        long int carry = 0;
        long int cl = b - '0';
        while(i>=0 || carry!=0){

            long int num = (i>=0? a[i] : '0')-'0';
            long int sol  = num*1l*cl + carry;
            carry = sol/10;
            result.push_back((sol%10)+'0');
            i--;
        }
        reverse(result.begin() , result.end());
        // cout<<result<<endl;
        return result;
    }
    string multiply(string num1, string num2) {
        string final = "0";
        int k=0;
        for(int i=num2.size()-1;i>=0;i--){
            string str = product(num1 , num2[i]);
            for(int j=0;j<k;j++) str.push_back('0');
            k++;
           final = sum(final ,str);
        }
        while(final.size()>1 && final[0]=='0') final.erase(0,1);
        return final;
    }
};



// Optimal Approach



/*

class Solution {
public:
    string multiply(string nums1, string nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(nums1=="0"||nums2=="0") return "0";
        vector<int>temp(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                temp[i+j+1]+=(nums1[i]-'0')*(nums2[j]-'0');
                temp[i+j]+=temp[i+j+1]/10;
                temp[i+j+1]%=10;
            }
        }
        string ans="";
        int i=0;
        while(i<n+m&&temp[i]==0)i++;
        while(i<n+m){
          ans.push_back(temp[i]+'0');
            i++;
        }
        return ans;
    }
};

*/
