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
  Firstly , traverse the tree in Inorder manner (left , root , right)
  and since the property of BST is that - left < root < right
  and we store these elements one after another in our storage array 
    firstly left then root then right.
  so , after array creation , we can check that is there any element in the array which is less than or equal to previous one.
  If there is , then we got that this is not BST.
  because , if at any point , if any element is less than or equal to previous one then it is possible in 2 cases only:
        Either root <= left
        or right <= root
*/

class Solution {
public:

    void traverse(TreeNode* root , vector<int>& storage){
        if(root == NULL) return;
        traverse(root->left , storage);
        storage.push_back(root->val);
        traverse(root->right , storage);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> storage;
        traverse(root , storage);
        for(int i=1;i<storage.size();i++){
            if(storage[i]<=storage[i-1]) return false;
        }
        return true;
    }
};
