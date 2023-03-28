//{ Driver Code Starts
//Initial Template for C++


/*
  What we do here is that :-
    for every NULL node , we return zero
    and if any node value in leftSubtree of root is greater than the root->val then return -1;
    same if any node value in rightSubtree of root is lesser than the root->val then return -1;
    otherwise return (lf + rt + 1) {according to the condition , means if (left!=NULL) then use value lf and 
    if (right!=NULL) then use value rt.
    and return lf + rt + 1 (means node in left + node in right + 1 {root})
*/



#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    int maxi = -1;
    bool checkLeft(int val , Node* root){
        // if(root==NULL) return false;
        if(root->left)
        if(checkLeft(val , root->left)==false) return false;
        if(root->data >= val) return false;
        if(root->right)
        if(checkLeft(val , root->right)==false) return false;
        return true;
    }
    
    bool checkRight(int val , Node* root){
        // if(root==NULL) return false;
        if(root->left)
        if(checkRight(val , root->left)==false) return false;
        if(root->data <= val) return false;
        if(root->right)
        if(checkRight(val , root->right)==false) return false;
        return true;
    }
    int traverse(Node* root){
        if(root == NULL) return 0;
        int lf = traverse(root->left);
        int rt = traverse(root->right);
        // cout<<lf<<" "<<rt<<endl;
        if(lf==-1 || rt==-1) return -1;
        if(lf==0 && rt==0){maxi = max(maxi , 1); return 1;}
        if(lf>0 && rt>0){
            if((root->left->data >= root->data) || (root->right->data <= root->data)) return -1;
           else{
               if(checkLeft(root->data , root->left) && checkRight(root->data , root->right)){
                    maxi = max(maxi , lf+rt+1);
                    return lf+rt+1;   
               }else return -1;
           }
        }
        else if(lf){
            if((root->left->data >= root->data)) return -1;
           else{
               if(checkLeft(root->data , root->left)){
                    maxi = max(maxi , lf+1);
                    return lf+1;   
               }else return -1;
           }
        }
        else if(rt){
            if((root->right->data <= root->data)) return -1;
           else{
               if(checkRight(root->data , root->right)){
                    maxi = max(maxi , rt+1);
                    return rt+1;   
               }else return -1;
           }
        }
    }
    int largestBst(Node *root)
    {
    	traverse(root);
    	return maxi;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends
