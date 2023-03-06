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
    Here , we check if current value is Even then in that case:
                      we took all grandElements of current node if exists:
                              * left->left
                              * left->right
                              * right->left
                              * right->right
 */

class Solution {
public:
    int sum = 0;

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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return sum;
        if(!(root->val & 1)){
            if(root->left != NULL){
                if(root->left->left != NULL) sum += root->left->left->val;
                if(root->left->right != NULL) sum += root->left->right->val;
            }
            if(root->right != NULL){
                 if(root->right->left != NULL) sum += root->right->left->val;
                if(root->right->right != NULL) sum += root->right->right->val;
            }
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);

        return sum;
    }
};
