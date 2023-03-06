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
  Here , we apply a traversal , 
        left - right - root;
         and at every node , we return 2 values - (sum , count)
              sum = sum of its subtree nodes including node value;
              count = count of its subtree nodes including its own;
        for(leaf node) = we return {0 , 0};
        and for upper node = we return {calSum , calCount};
              Where , 
                  calSum = left subtree sum + right subtree sum + root value (current node value);
                  calCount = left subtree count + right subtree count + 1 (for that current node);
*/
// pair<int,int> : first int is for sum and second one for count; 

class Solution {
public:
    int cnt = 0;
    pair<int,int> traverse(TreeNode* root){
        if(root==NULL) return {0 , 0};
        pair<int,int> a = traverse(root->left);
        pair<int,int> b = traverse(root->right);
        int calSum = a.first + b.first + root->val;
        int calCount = a.second+b.second+1;
        int value = calSum/calCount;
        if(value == root->val) cnt++;
        return {calSum , calCount};
    }
    int averageOfSubtree(TreeNode* root) {
        auto a = traverse(root);
        return cnt;
    }
};
