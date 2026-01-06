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
    int maxLevelSum(TreeNode* root) {
        int level = 0, ans = INT_MIN, lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            lvl++;
            int n = q.size(),sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
                sum+=node -> val;
            }
            if(sum > ans) {
                ans = sum;
                level = lvl;
            }
        }
        return level;
    }
};