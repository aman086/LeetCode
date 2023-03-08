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
  Here , we simply traverse the tree in InOrder manner , so we get our treeNode in sorted manner
    then assign the middle node to the root and 
    root->left = start to mid-1;
    root->right = mid+1 to end;
    we do this on and on until we reach our base condition.
*/


class Solution {
public:
    vector<TreeNode*> inOrderStore;
    void traverseInOrder(TreeNode* root){
        if(!root) return;
        traverseInOrder(root->left);
        inOrderStore.push_back(root);
        traverseInOrder(root->right);
    }

    TreeNode* construct(TreeNode*& root , int start ,int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        root = inOrderStore[mid];
        root->left = construct(root->left , start , mid-1);
        root->right = construct(root->right , mid+1 , end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
        traverseInOrder(root);
        return construct(root , 0 , inOrderStore.size()-1);
    }
};
