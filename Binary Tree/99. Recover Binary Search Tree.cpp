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
  We apply the same rule , what we applied if we had a sorted array where only 2 elements mismatched
  then the same logic is applied here
  we start traversing from i=0 to n-1;
  int first , second , prev;
  
  if at any point, we got that current element is less than previous one then we
    assign previous to first and current to second
    and assigning to first is done at only once
    if(we assign the first then again we do not assign it)
    but at everypoint where prev is greater than current then we assign current to second (second == current)
*/


class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void traverse(TreeNode* root){
        if(root == NULL) return;
        traverse(root->left);
        if(prev && (root->val < prev->val)){
            if(!first){
                first = prev;
            }
            second = root;
        }
        prev = root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {

        traverse(root);
        if(first && second) swap(first->val , second->val);
    }
};
