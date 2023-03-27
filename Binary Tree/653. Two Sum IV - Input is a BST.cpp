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
Working same as Leetcode que - 1.two sum works
for sorting array use Inorder traversal
*/

class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        bool vl = findTarget(root->left , k);
        if(vl) return true;
        if(st.find(k-root->val)!=st.end()) return true;
        st.insert(root->val);
        bool vl_ = findTarget(root->right,k);
        if(vl_) return true;
        return false;
    }
};
