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
  Here , we simply maintain a queue for TreeNode and one stack for values 
    at every even level , I add values of nodes into stack and 
    at every odd level , I push values into queue , because stack is working in LIFO manner
      that's how , I solved the question
*/


class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        stack<int> s;
        bool even = true;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr_q = q.front();
                q.pop();
                if(!even){
                     curr_q->val = s.top();
                     s.pop();
                }
                if(curr_q->left) {q.push(curr_q->left); if(even) s.push(curr_q->left->val);}
                if(curr_q->right) {q.push(curr_q->right); if(even) s.push(curr_q->right->val);}
            }
            even = !even;
        }
        return root;
    }
};
