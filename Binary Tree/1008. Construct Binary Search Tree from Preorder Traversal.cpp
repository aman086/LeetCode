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
      we check for the first element is array which is greater than our current starting element.
            then , we divide the array into 2 parts:
                part - 1 => In this part , all minimum no exists
                part - 2 => In this part , all maximum no exists.
                
                and do this on and on recursively until base condition found 
                  base condition = either 1 or 2 element remaining then stop searching and assign value manually , based on their value
                  
*/


class Solution {
public:

    void traverse(TreeNode*& root , vector<int>& preorder , int start , int end){
        if(start > end) return;
        root = new TreeNode(preorder[start]);
        if(end-start == 0) return;
        if(end - start == 1){
            if(preorder[end]>preorder[start])
                root->right = new TreeNode(preorder[end]);
            else
                root->left = new TreeNode(preorder[end]);

            return;       
        }
        int i;
        for(i=start+1;i<=end;i++){
            if(preorder[i] > preorder[start]) break;
        }

        traverse(root->left , preorder , start+1 , i-1);
        traverse(root->right ,preorder , i , end);

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        int i;
        for(i=1;i<n;i++){
            if(preorder[i] > root->val) break;
        }
        traverse(root->left , preorder , 1 , i-1);
        traverse(root->right , preorder , i , n-1);
        return root;
    }
};
