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
 Here , 
   we first go on deep and when there is no deep possible then check
   current node value .
   if current node value != 1
   and left and right == NULL then make this node is also NULL
   and return current node to the parents , 
   so that they can also check the same condition for himshelf.
   Before checking the condition for parent , checking for child must be
   completed.
   
*/


class Solution {
public:
    // TreeNode* remove(TreeNode*& root){
    //     if(!root) return;

    //     if(root->left) remove(root->left);
    //     if(root->right) remove(root->right); 

    //     if(root->val != 1 && !root->left && !root->right){
    //         root = NULL;
    //         //  return;
    //     }
    //     return root;   
    // }
    TreeNode* pruneTree(TreeNode*& root) {
        if(root->left) pruneTree(root->left);
        if(root->right) pruneTree(root->right); 

        if(root->val != 1 && !root->left && !root->right){
            root = NULL;
        }
        return root;  
    }
};
