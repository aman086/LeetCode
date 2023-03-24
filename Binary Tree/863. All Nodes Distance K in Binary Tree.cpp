/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> finalAns;
    void findingTheParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& mp){
         queue<TreeNode*> q;
         q.push(root);
         while(!q.empty()){
             int sz = q.size();
             for(int i=0;i<sz;i++){
                 auto node = q.front();
                 q.pop();
                 if(node->left){
                     q.push(node->left);
                     mp[node->left] = node;
                 }
                 if(node->right){
                     q.push(node->right);
                     mp[node->right] = node;
                 }
             }
         }
    }

    void searching(int k , TreeNode* root , int distanceTillNow , unordered_map<TreeNode* , bool>& visited , unordered_map<TreeNode* , TreeNode*>& mp){
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto tp = q.front();
                q.pop();
                auto node = tp.first;
                int vl = tp.second;
                visited[root] = true;
                if(vl == k)
                 finalAns.push_back(node->val);
                 else
                  {
                      if(!visited[node->left]){
                          if(node->left) q.push({node->left , vl + 1});
                          visited[node->left] = true;
                      }
                      if(!visited[node->right]){
                          if(node->right) q.push({node->right , vl + 1});
                          visited[node->right] = true;
                      }
                      if(!visited[mp[node]]){
                          if(mp[node]) q.push({mp[node] , vl + 1});
                          visited[mp[node]] = true;
                      }
                  }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> mp;
        unordered_map<TreeNode* , bool> visited;
        mp[root] = NULL;
        findingTheParent(root , mp);
        // Starting from target node
        searching(k ,target , 0 , visited , mp);
        return finalAns;
    }
};
