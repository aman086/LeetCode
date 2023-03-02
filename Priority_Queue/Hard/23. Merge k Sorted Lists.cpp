/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
  Simply , extract val part of each node and put them into priority queue and then make a linked list with those data values in ascending order
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode* root = new ListNode(123456);
         ListNode* cur = root;
         priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it : lists){
            ListNode* curr = it;
            while(curr!=NULL){
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        // root = root->next;
        while(!pq.empty()){
            root->next = new ListNode(pq.top());
            pq.pop();
            root = root->next;
        }
        return cur->next;
    }
};
