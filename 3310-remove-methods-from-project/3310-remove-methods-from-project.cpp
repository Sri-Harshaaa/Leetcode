class Solution {
public:
    void solve(int u, vector<vector<int>>& adj, vector<bool>& infected) {
        infected[u] = true;

        for(int v : adj[u]) {
            if(!infected[v]) solve(v,adj,infected);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<int> sol;
        for(int i=0; i<n; i++) sol.push_back(i);
        vector<bool> infected(n, false);
        vector<vector<int>> adj(n);
        int e = invocations.size();
        for(int i=0; i<e; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }
        solve(k,adj,infected);

        for(int i=0; i<n; i++) {
            if(!infected[i]) {
                for(int v : adj[i]) {
                    if(infected[v]) return sol;
                }
                ans.push_back(i);
            }
        }

        return ans;
    }
};