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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* hd = root;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        while(head1!=NULL && head2!=NULL){
            root->next = new ListNode((head1->val + head2->val + carry)%10);
            if((head1->val + head2->val + carry)>=10)
             carry = 1;
            else
             carry = 0; 
            root = root->next;
            head1 = head1->next;
            head2 = head2->next; 
        }
    
        while(head1!=NULL){
            root->next = new ListNode((head1->val + carry)%10);
            if((head1->val + carry)>=10) carry = 1;
            else carry = 0;
            head1 = head1->next;
            root = root->next;
        }
        while(head2!=NULL){
            root->next = new ListNode((head2->val + carry)%10);
            if((head2->val + carry)>=10) carry = 1;
            else carry = 0;
            head2 = head2->next;
            root = root->next;
        }
        if(head1==NULL && head2==NULL){
            if(carry==1)
                root->next = new ListNode(1);   
        }
        return hd->next;
    }

    /*
    
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
       }

    */
};
