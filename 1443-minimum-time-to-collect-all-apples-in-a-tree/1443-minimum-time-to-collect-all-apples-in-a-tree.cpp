class Solution {
public:
    int solve(int u, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int ans = 0;
        for(int& v : adj[u]) {
            if(v != parent) {
                int steps = solve(v,u,adj,hasApple);
                if(steps) ans+=(steps+2);
                else if(hasApple[v]) ans+=2; 
            }
        }
        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return solve(0,-1,adj,hasApple);
    }
};