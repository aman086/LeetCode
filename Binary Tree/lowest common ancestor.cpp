/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
  If any node contains p or q then it must return node otherwise return NULL;
  if at any point left Subtree and right Subtree both returns some value except NULL means that p and q present in both subtrees then that node is our LCA
  so we return that node to the parent
  if at any point , any node returning any value except NULL then we also return our current root to our parent in place of NULL which indicates that , target is also present here
  
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root==p || root==q) return root;
        TreeNode* lf = lowestCommonAncestor(root->left , p , q);
        TreeNode* rt = lowestCommonAncestor(root->right , p , q);
        if(lf==NULL && rt==NULL) return NULL;
        if(lf!=NULL && rt!=NULL) return root;
        if(lf!=NULL) return lf;
        return rt;
    }
};
