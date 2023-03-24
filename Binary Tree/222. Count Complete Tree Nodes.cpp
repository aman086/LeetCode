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

    int leftCount(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + leftCount(root->left);
    }

    int rightCount(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + rightCount(root->right);
    }


    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lf = leftCount(root);
        int rt = rightCount(root);
        // cout<<lf<<" "<<rt<<endl;
        if(lf == rt) return ((1<<lf) - 1);
        // int vl_lf = countNodes(root->left);
        // int vl_rt = countNodes(root->right);
        // cout<<vl_lf<<" "<<vl_rt<<endl;
        // return 1 + vl_lf + vl_rt;
        return (1 + countNodes(root->left) + countNodes(root->right));
        // return 0;
    }
};
