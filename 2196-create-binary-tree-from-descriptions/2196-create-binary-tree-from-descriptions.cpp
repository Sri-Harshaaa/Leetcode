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
        int n = 1e5+1;
        vector<int> parent(n,-1);
        unordered_set<int> st;

        unordered_map<int,TreeNode*> mp;

        for(int i=0; i<descriptions.size(); i++) {
            int u = descriptions[i][0];
            int v = descriptions[i][1];
            int w = descriptions[i][2];

            st.insert(u);
            st.insert(v);

            parent[v] = u;

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

        int root = -1;

        for(auto& v : st) {
            if(parent[v] == -1) {
                root = v;
                break;
            }
        }

        return mp[root];
    }
};