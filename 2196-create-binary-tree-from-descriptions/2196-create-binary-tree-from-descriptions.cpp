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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,bool> mpp;
        int root = -1;
        for(int i=0; i<descriptions.size(); i++) {
            int u = descriptions[i][0];
            mpp[u] = false;
        }
        for(int i=0; i<descriptions.size(); i++) {
            int v = descriptions[i][1];
            if(mpp.count(v)) mpp[v] = true;
        }
        for(auto& it : mpp) {
            if(!it.second) {
                root = it.first;
                break;
            }
        }

        unordered_map<int,TreeNode*> mp;

        for(int i=0; i<descriptions.size(); i++) {
            int u = descriptions[i][0];
            int v = descriptions[i][1];
            int w = descriptions[i][2];

            if(!mp.count(u)) {
                TreeNode* par = new TreeNode(u);
                mp[u] = par;
            }
            if(!mp.count(v)) {
                TreeNode* child = new TreeNode(v);
                mp[v] = child;
            }

            TreeNode* par = mp[u];
            TreeNode* child = mp[v];

            if(w) par->left = child;
            else par->right = child;
        }

        return mp[root];
    }
};