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
class Solution {
public:
    int currIndex;
    TreeNode* partition(int start , int end , vector<int>& preorder, vector<int>& inorder){
        if(start > end) return NULL;
        if(currIndex == preorder.size()) return NULL;
        if(start == end){
            if(inorder[start]==preorder[currIndex]){
                TreeNode* node = new TreeNode(preorder[currIndex]);
                currIndex++;
                return node;
            }
            return NULL;
        }
        int middle;
        for(int i=start;i<=end;i++){
            if(inorder[i]==preorder[currIndex]){
                middle =  i;
                currIndex++;
                break;
            }
        }
        TreeNode* node = new TreeNode(inorder[middle]);
        node->left = partition(start , middle-1 , preorder,inorder);
        node->right = partition(middle+1 , end , preorder , inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        int n = inorder.size();
        currIndex = 0;
        root = partition(0 , n-1 , preorder , inorder);
        return root;
    }
};
