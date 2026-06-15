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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        sum+=root->val;
        if(!root->left && !root->right) {
            if(sum == targetSum) return true;
            else {
                sum-=root->val;
                return false;
            }
        }

        if(hasPathSum(root->left,targetSum)) return true;
        if(hasPathSum(root->right,targetSum)) return true;
        sum-=root->val;

        return false; 
    }
};