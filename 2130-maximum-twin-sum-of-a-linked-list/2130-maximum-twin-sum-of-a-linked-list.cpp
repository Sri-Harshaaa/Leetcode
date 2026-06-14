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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* node = head;
        while(node) {
            arr.push_back(node->val);
            node = node->next;
        }
        int ans = -1;
        int n = arr.size();
        for(int i=0; i<n/2; i++) {
            ans=max(ans,arr[i]+arr[n-1-i]);
        }
        return ans;
    }
};