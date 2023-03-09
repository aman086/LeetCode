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
    Here ,at every point , we have to maintain 2 variables 
        maxi and mini
        and compare everytime with our global variable ans;
          ans = max(ans , abs(maxi - mini));
        If we find any value greater than maxi then change maxi and also check the difference,
        similarly ,
            If we find any value smaller then mini then change mini and also check the difference.
        that's how , at any point : we find difference of overall child maxi and overall child mini;
        that's how , our ans is updated automatically.
        
*/
class Solution {
public:

//    My Approach :-


    // int maxi = INT_MIN;
    // void perform(TreeNode* root){
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int vl = root->val;
    //     while(!q.empty()){
    //         int sz = q.size();
    //         for(int i=0;i<sz;i++){
    //             auto curr = q.front();
    //             maxi = max(maxi , abs(vl - curr->val));
    //             q.pop();
    //             if(curr->left) q.push(curr->left);
    //             if(curr->right) q.push(curr->right);
    //         }
    //     }
    //     if(root->left) perform(root->left);
    //     if(root->right) perform(root->right);
    // }
    // // void traverse(TreeNode* root){
    // //     if(root->left) {perform(root->left); traverse(root->left);}
    // //     if(root->right) {perform(root->right); traverse(root->right);}
        
    // // }
    // int maxAncestorDiff(TreeNode* root) {
    //      if(root)
    //      perform(root);
    //     //  traverse(root);
    //      return maxi;
    // }


//  Approach after upsolving:
        int ans = INT_MIN;
        void traverse(TreeNode* root , int mini , int maxi){
            if(!root) return;

            if(root->val > maxi) maxi = root->val;
            if(root->val < mini) mini = root->val;

            ans = max(ans , abs(maxi - mini));
            traverse(root->left , mini , maxi);
            traverse(root->right , mini , maxi);
        }
        int maxAncestorDiff(TreeNode* root) {
            if(!root) return 0;
            traverse(root , root->val , root->val);
            return ans;
        }
};
