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
class Solution {
public:
    long sum = 0;
    long maxP = 0;

    int tot_sum(TreeNode* node) {
        if(node == NULL) return 0;
        int left = tot_sum(node -> left);
        int right = tot_sum(node -> right);
        int sum = node -> val + left + right;
        return sum;
    }

    int find(TreeNode* node) {
        if(node == NULL) return 0;
        int left = find(node -> left);
        int right = find(node -> right);
        int curr_sum = node -> val + left+right;
        long temp = sum - curr_sum;
        maxP = max(maxP, curr_sum*temp);
        return curr_sum;
    }

    int maxProduct(TreeNode* root) {
        sum = tot_sum(root);
        find(root);
        return maxP % 1000000007;
    }
};