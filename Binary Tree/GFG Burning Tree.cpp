/*
We have to follow some simple steps:

 1. Maintain a map for child->parent (for every child , store its parent)
 2. then find the pointer of target node by any traversal (let's say Inorder,PreOrder,PostOrder);
 3. then run a BFS and go on both child as well as parent and maintain a hashMap (Visited) for not repeating the same node again and again
 4. and every time , compare and store maximum value of steps;
 
*/

class Solution {
  public:
   Node* tar;
   int step;
    void findingTheParent(Node* root , unordered_map<Node* , Node*>& mp){
         queue<Node*> q;
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
    
    
        void searching(Node* root , unordered_map<Node* , bool>& visited , unordered_map<Node* , Node*>& mp){
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        step = 0;
        visited[root] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto tp = q.front();
                q.pop();
                auto node = tp.first;
                int vl = tp.second;
                step = max(step , vl);
                // visited[root] = true;
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
    
    void returnAddress(Node* root , int target){
        if(root==NULL) return;
        if(root->data == target) {tar = root; return;}
        returnAddress(root->left , target);
        returnAddress(root->right , target);
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node* , Node*> mp;
        unordered_map<Node* , bool> visited;
         mp[root] = NULL;
        findingTheParent(root , mp);
        returnAddress(root , target);
        searching(tar , visited , mp);
        return step;
        
    }
};
