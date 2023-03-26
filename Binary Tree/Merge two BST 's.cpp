//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    stack<Node*> st;
    void maintainStorage(Node* root , stack<Node*>& s){
        for(;root!=NULL;root=root->left){
            s.push(root);
        }
        return;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       maintainStorage(root1 , st);
       vector<int> ans;
       vector<int> ans1;
       vector<int> answer;
       while(!st.empty()){
           auto node = st.top();
           st.pop();
           ans.push_back(node->data);
           maintainStorage(node->right , st);
       }
       maintainStorage(root2 , st);
       while(!st.empty()){
           auto node = st.top();
           st.pop();
           ans1.push_back(node->data);
           maintainStorage(node->right , st);
       }
       int i=0;
       int j=0;
       while(i<ans.size() && j<ans1.size()){
           if(ans[i]>ans1[j]){
               answer.push_back(ans1[j++]);
           }else{
               answer.push_back(ans[i++]);
           }
       }
       
       while(i<ans.size()){
           answer.push_back(ans[i++]);
       }
       while(j<ans1.size()){
           answer.push_back(ans1[j++]);
       }
       return answer;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends
