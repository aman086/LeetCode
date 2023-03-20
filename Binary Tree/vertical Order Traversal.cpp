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
  At any level , if for any column , there is multiple elements then we need to sort it and then add it to our finalAns;
  so we use map<int,map<int,multiset>> mp;
*/
class Solution {
public:
     vector<vector<int>> finalAns;
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode* , pair<int , int>>> q;
        map<int , map<int , multiset<int>>> mp;
        q.push({root ,{0 , 0}});

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto cur = q.front();
                q.pop();
                TreeNode* node = cur.first;
                int vertical = cur.second.first;
                int level = cur.second.second;
                mp[vertical][level].insert(node->val);
                if(node->left) q.push({node->left , {vertical-1 , level+1}});
                if(node->right) q.push({node->right , {vertical+1 , level+1}});
            }
        }
        
        for(auto it : mp){
            vector<int> curr;
            for(auto st : it.second){
                curr.insert(curr.end() , st.second.begin() , st.second.end());
            }
            finalAns.push_back(curr);
        }
        return finalAns;
    }
};
