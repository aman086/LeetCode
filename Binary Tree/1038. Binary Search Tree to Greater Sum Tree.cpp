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

/*
  We apply a traversal ...
          right -> root -> left;
          and sum of all the elements , we found in the path between;
          and return that sum variable;
*/


class Solution {
public:

    void postOrder(TreeNode* &root , int& sum){
        if(root==NULL) return;
        postOrder(root->right , sum);
        root->val += sum;
        sum = root->val;
        postOrder(root->left , sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        // TreeNode* root = new TreeNode(1);
        int sum = 0;
        postOrder(root , sum);
        return root;
    }
};
