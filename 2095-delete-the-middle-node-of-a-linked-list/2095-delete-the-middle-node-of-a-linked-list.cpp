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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next) slow = slow->next;
        if(!slow->next) {
            fast->next = NULL;
            return head;
        }

        slow->val = slow->next->val;
        ListNode* temp = slow->next->next;
        slow->next->next = NULL;
        slow->next = temp;

        return head;
    }
};