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
  Here , In this question :
    we maintain a variable stepCount for counting the steps
    and at every recursive call , we return the steps , we required for maintaining that subtree's every node value = 1.
    if(root->val == 1) {
          it means that this node is not able to give coin to its child and also no need of any coin for itself;
    }else if(root->val < 1){
        it means that current node also wants 1 coin for itself.
        so if child is able to fulfill his requirement then okk otherwise if child also wants coin then it combines
        his need of coin with child need of coin and give it to parents.
    }else{
        it means that if current node value is greater than 1 , so it is able to give some coin to his child/parent or both
        so , it asks from his child , if then need then it fulfills their requirement and after that , it returns remaining coin
        to the parent .
        there may be such case possible that while giving coin to child , that node losts its own coin too
        then it asks for requirement of itself with its child requirement and return to the parent
    }
*/


class Solution {
public:
    int stepCount = 0;
    int traverse(TreeNode* root){
        if(!root) return 0;
        int lt = traverse(root->left);
        int rt =  traverse(root->right);
        stepCount += (abs(lt) + abs(rt));
        if(root->val == 1)
            return lt + rt ;
        
        else if(root->val < 1)
            return -1 + rt + lt;
        
        // else ::=>>  if(root->val > 1)
        return (root->val - 1) + (lt + rt);
    }
    int distributeCoins(TreeNode* root) {
        traverse(root);
        return stepCount;
    }
};

// In every case return statement , we are returning the same thing , (root->val -  1 + lt + rt)
//  that is the key point of better optimization



//  Best Code for some other coder

class Solution {
    int helper(TreeNode* root,int &ct){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left,ct);
        int right=helper(root->right,ct);
        ct+= abs(left)+abs(right);
        return root->val-1+left+right;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ct=0;
        helper(root,ct);
        return ct;
    }
};
