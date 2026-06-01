class Solution {
public:
    vector<int> maybe1, maybe2;

    int solve(int u, int parent, vector<vector<int>>& adj, string& s) {
        int m1 = 0, m2 = 0;
        for(int& v : adj[u]) {
            if(v == parent) continue;
            int sol = solve(v,u,adj,s);
            if(s[u] == s[v]) {
                maybe1.push_back(sol);
                continue;
            }
            if(sol >= m1) {
                m2 = m1;
                m1 = sol;
            }
            else if(sol > m2) m2 = sol;
        }
        maybe2.push_back(m1+m2+1);
        return m1+1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans = solve(0,-1,adj,s);
        int maxi1 = -1, maxi2 = -1;
        if(maybe1.size() > 0) maxi1 = *max_element(maybe1.begin(), maybe1.end());
        if(maybe2.size() > 0) maxi2 = *max_element(maybe2.begin(), maybe2.end());

        return max({ans,maxi1,maxi2});
    }
};