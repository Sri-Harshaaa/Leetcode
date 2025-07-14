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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        string s = "";
        ListNode* temp = head;
        while(temp!=NULL) {
            s+=to_string(temp->val);
            temp = temp->next;
        }
        int n = s.size();
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='1') {
                num+=pow(2,n-1-i);
            }
        }
        return num;
    }
};