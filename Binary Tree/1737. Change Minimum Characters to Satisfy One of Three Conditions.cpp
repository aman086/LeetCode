
class Solution {
public:
    int minCharacters(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();

        map<int,int> mp_a;
        map<int,int> mp_b;
        int max_count_a = 0;
        int max_count_b = 0;
        vector<int> hsh_a(26);
        vector<int> hsh_b(26);
        for(int i=0;i<n1;i++){
             mp_a[a[i]-'a']++;
             max_count_a = max(max_count_a , mp_a[a[i]-'a']);
        }
        for(int i=0;i<n2;i++){
             mp_b[b[i]-'a']++;
            max_count_b = max(max_count_b , mp_b[b[i]-'a']);
        }
        hsh_a[0] = 0;
        hsh_b[0] = 0;
        for(int i=1;i<26;i++){
            hsh_a[i] = hsh_a[i-1] + mp_a[i-1];
        }
        for(int i=1;i<26;i++){
            hsh_b[i] = hsh_b[i-1] + mp_b[i-1];
        }

        int minOperation;
        minOperation = n1-max_count_a + n2-max_count_b;
        // cout<<n1<<" "<<n2<<endl;
        // cout<<hsh_a[1]<<" "<<hsh_b[1]<<endl;
        for(int i=1;i<26;i++){
            minOperation = min(minOperation , hsh_a[i] + (n2 - hsh_b[i]));
            minOperation = min(minOperation , hsh_b[i] + (n1 - hsh_a[i]));
        }
        
        return minOperation;
    }
};
