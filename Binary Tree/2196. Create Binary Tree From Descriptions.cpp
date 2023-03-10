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
  Here , I maintain a hash table ( Unordered_map )
  first element of map is for number (child/parent)
  first element of pair is for TreeNode of number
  second element of pair is for validation of child number
  we make child element true.
  because our main aim to return the root
  so , for identification of root , we maintain a bool variable - means that if it is false means that it never become child
  and this is the property of root.
  a node which never became child of any node , that is our root node
*/


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , pair<TreeNode* , bool>> mp;
        unordered_map<int,bool> check;
        TreeNode* root = NULL;
        for(auto it : descriptions){
            int parent = it[0];
            int child = it[1];
            int vl = it[2];
            TreeNode* node;
            if(mp[parent].first == NULL){
                node = new TreeNode(parent);
                // root = node;
                mp[parent].first = node;
            }
            node = mp[parent].first;
            TreeNode* chl;
            // if(root == NULL) root = mp[parent].first; 
            if(mp[child].first == NULL)  {chl = new TreeNode(child); mp[child].first = chl;  }
            chl = mp[child].first ; 

            if(vl == 1)
              node->left = chl;
            else
                node->right = chl;  

            mp[child].second = true;    
        }
            for(auto it : descriptions){
                if(!mp[it[0]].second) root = mp[it[0]].first;
            }
         return root;         
        }
};


// best solution :


    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , pair<TreeNode* , bool>> mp;
        TreeNode* root = NULL;
        for(auto it : descriptions){
           
            if(mp.count(it[0])==0) mp[it[0]].first = new TreeNode(it[0]);
            if(mp.count(it[1])==0) mp[it[1]].first = new TreeNode(it[1]);
  // this count() function is for checking that this number is present or not
  // if count == 0 means that not present , otherwise present. 

    (it[2]) ? mp[it[0]].first->left = mp[it[1]].first :  mp[it[0]].first->right = mp[it[1]].first;  

            mp[it[1]].second = true;    
    }

// we have to find its alternative , because this below code increasing the time complexity      
for(auto it : descriptions){
    if(!mp[it[0]].second) root = mp[it[0]].first;
}
         return root;         
        }
};
