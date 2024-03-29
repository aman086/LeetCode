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
    void setKro(TreeNode* lf , TreeNode*& rt){
        if(rt->left == NULL){ rt->left = lf; return;}
        setKro(lf , rt->left);
    }

    void traverse(TreeNode* root , TreeNode*& parent , TreeNode*& target , int key){
        if(root == NULL) return;

        if(root->right){
            if(root->val < key){
            if(root->right->val == key){
                parent = root;
                target = root->right;
                return;
            }else
              traverse(root->right , parent , target , key);
            }
        }
    if(root->left){
        if(root->val > key){
            if(root->left->val == key){
                parent = root;
                target = root->left;
                return;
            }else
              traverse(root->left , parent , target , key);
        } 
    }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;
            setKro(root->left , root->right);
            return root->right;
        }
        TreeNode* parent = NULL;
        TreeNode* target = NULL;
    // searching in O(log n ) complexity    
        traverse(root , parent , target , key);

     // searching in O(n) complexity


        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int sz = q.size();
        //     bool found = false;
        //     for(int i=0;i<sz;i++){
        //         auto tp = q.front();
        //         q.pop();
        //         if(tp->left){
        //             if(tp->left->val == key){
        //                 parent = tp;
        //                 target = tp->left;
        //                 found = true;
        //                 break;
        //             }else
        //               q.push(tp->left);
        //         }   
        //         if(tp->right){
        //             if(tp->right->val == key){
        //                 parent = tp;
        //                 target = tp->right;
        //                 found = true;
        //                 break;
        //             }
        //             else q.push(tp->right);
        //         }
        //         if(found) break;
        //   }   
        // }
        if(parent==NULL && target==NULL) return root;
        TreeNode* temp;
        if(target->left==NULL && target->right==NULL){
            temp = NULL;
            if(parent->left == target) parent->left = NULL;
            if(parent->right == target) parent->right = NULL;
            // target = NULL;
            return root;
        }
        //    temp = NULL;
        else if(target->right == NULL){
            temp = target->left;
            // target = NULL;
        }else if(target->left == NULL){
            temp = target->right;
        }
        else{
            setKro(target->left , target->right);
            temp = target->right;
        }

        if(parent->left == target) parent->left = temp;
        if(parent->right == target) parent->right = temp;
        return root;
    }
};
