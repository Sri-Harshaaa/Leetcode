class Solution {
public:
    int solve(int u, int parent, vector<vector<int>>& adj, string& s, int& ans) {
        int m1 = 0, m2 = 0;
        for(int& v : adj[u]) {
            if(v == parent) continue;
            int sol = solve(v,u,adj,s,ans);
            if(s[u] == s[v]) continue;
            if(sol >= m1) {
                m2 = m1;
                m1 = sol;
            }
            else if(sol > m2) m2 = sol;
        }
        ans = max(ans,m1+m2+1);

        return m1+1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans = 0;
        solve(0,-1,adj,s,ans);
        
        return ans;
    }
};