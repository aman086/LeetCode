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
First , count the number of target values in given tree 
and then start function calling of finding leaf node with target value and make it NULL. and decrease the count of our count variable.
do this on and on until base condition found.
base condition:
  * It may be possible that we remove leaf node with target value so , In that case our count variable became zero
      so , this could be our base condition. if(cnt==0) break;
  * and It is also possible that , there is no leaf node with value target so no mean for traversing next time again and again
      so , this could also be our base condition. if value of (cnt) before function call == value(cnt) after function call
      means that, no target value removed. 
      Which indicates that there is not any node which is able to remove. So , we stop here. 
      and apply a break condition.
      
*/

class Solution {
public:
    int cnt = 0;
    void remove(TreeNode*& root , int target){
        if(root == NULL) return;
         if(root->val == target){
             if(root->left == NULL && root->right == NULL){
                 root = NULL;
                 cnt--;
                 return;
             }
         }
         if(root->left != NULL) remove(root->left , target);
         if(root->right != NULL) remove(root->right , target);
    }
    
    void checkCount(TreeNode* root ,int target){
        if(root->left) checkCount(root->left , target);
        if(root->val == target) cnt++;
        if(root->right) checkCount(root->right , target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target){
         checkCount(root , target);
         while(true){
             if(cnt==0) break;
             int vl = cnt;
             remove(root , target);
             if(cnt == vl) break;
         }
         return root;
    }
};
