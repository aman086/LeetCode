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
 I made a variable sum , which is holding sum for current level
  If level increases then it is pointing to next level and holding that level sum.
    so , In this way we can calculate last level sum too
    and return it.
*/
class Solution {
public:

    int levelOrder(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while(!q.empty()){
            sum = 0;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front();
                sum+= (curr->val);
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        return levelOrder(root);
    }
};
