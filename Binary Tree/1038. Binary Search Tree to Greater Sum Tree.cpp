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
  100% Optimal....
  
  We apply a traversal ...
          right -> root -> left;
          and sum of all the elements , we found in the path between;
          and return that sum variable;
*/
class Solution {
public:
    int sum = 0;
    void postOrder(TreeNode* &root){
        if(root==NULL) return;
        postOrder(root->right);
        root->val += sum;
        sum = root->val;
        postOrder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        postOrder(root);
        return root;
    }
};

