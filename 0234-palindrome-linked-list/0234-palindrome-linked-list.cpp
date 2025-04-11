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
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL) {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            head=curr;
            curr=temp;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead= reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL) {
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};