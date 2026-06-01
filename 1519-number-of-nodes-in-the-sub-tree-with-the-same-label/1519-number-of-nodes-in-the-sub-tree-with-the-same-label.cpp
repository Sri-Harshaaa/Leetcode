class Solution {
public:
    void solve(int u, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ch, vector<int>& ans) {
        int before = ch[labels[u]-'a'];
        ch[labels[u]-'a']++;
        for(int& v : adj[u]) {
            if(v == parent) continue;
            solve(v,u,adj,labels,ch,ans);
        }
        int after = ch[labels[u]-'a'];
        ans[u] = after-before;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ch(26,0), ans(n,0);
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(0,-1,adj,labels,ch,ans);
        return ans;
    }
};