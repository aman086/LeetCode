/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        ans += (to_string(root->val));
        ans.push_back(' ');
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                if(node->left){
                    ans += (to_string(node->left->val));
                    ans.push_back(' ');
                    q.push(node->left);
                }else{
                    ans += (to_string(-1001));
                    ans.push_back(' ');
                }
                if(node->right){
                    ans += (to_string(node->right->val));
                    ans.push_back(' ');
                    q.push(node->right);
                }else{
                    ans += (to_string(-1001));
                    ans.push_back(' ');
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<int> ans(1,0);
        stringstream ss(data);
        string word;
        int cnt=0;
        while(ss >> word){
            if(cnt==0){ans.pop_back();cnt++;}
            ans.push_back(stoi(word));
        }
        queue<pair<int , TreeNode*>> q;
        TreeNode* root = new TreeNode(ans[0]);
        q.push({ans[0] , root});
        int currIndex=0;
        int n = ans.size();
        while(!q.empty()){
            auto tp = q.front();
            int fir = tp.first;
            auto node = tp.second;
            q.pop();
            if((currIndex + 1)<n && ans[++currIndex] != -1001){
                node->left = new TreeNode(ans[currIndex]);
                q.push({ans[currIndex] , node->left});
            }
            if((currIndex + 1)<n && ans[++currIndex] != -1001){
                node->right = new TreeNode(ans[currIndex]);
                q.push({ans[currIndex] , node->right});
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
