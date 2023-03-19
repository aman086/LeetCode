/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = 0;
    void dfs(TreeNode* root, bool lf , int len){
        maxi = max(maxi , len);
        if(lf){
            if(root->right) dfs(root->right , false , len+1);
            if(root->left) dfs(root->left , lf , 1);
        }else{
            if(root->left) dfs(root->left , true , len+1);
            if(root->right) dfs(root->right , lf , 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        // int len = 0;
        dfs(root , true , 0);
        // dfs(root , false , 0);
        return maxi;
    }
};
