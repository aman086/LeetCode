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
    Here , In this question 
      I simply make a function named "recover" , which converts the given tree into newly formed tree according to the question requirements,
      and while making a recover tree , parallely I am adding those elements into unordered_map and mark it as true;
      so that , In find function I can use it properly , In O(1) time complexity;
      
      Maintainning unordered_map is a key factor
     
*/


class FindElements {
public:
    TreeNode* root = new TreeNode();
    unordered_map<int,bool> finalAns;
    void recover(TreeNode*& curr){
        queue<TreeNode*> q;
        finalAns[0] = true;
        q.push(curr);
        curr->val = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front();
                q.pop();
                if(curr->left) { curr->left->val = curr->val*2 + 1; finalAns[curr->val*2 + 1] = true; q.push(curr->left);}
                if(curr->right) { curr->right->val = curr->val*2 + 2; finalAns[curr->val*2 + 2] = true; q.push(curr->right);}
            }
        }
    }
    FindElements(TreeNode* root) {
        this->root = root;
        recover(root);
    }
    
    bool find(int target) {
            return finalAns[target];  
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
