class Solution {
public:
    int MOD = 1e9 + 7;

    int depth(int u, int parent, vector<vector<int>>& adj) {
        int dep = 0;
        for(int& v : adj[u]) {
            if(v == parent) continue;

            int sol = depth(v,u,adj);
            dep = max(dep,sol+1);
        }

        return dep;
    }

    int power(long long a, long long b) {
        int res = 1;

        while(b > 0) {
            if(b&1) {
                res = ((res%MOD)*(a%MOD))%MOD;
            }

            a = ((a%MOD)*(a%MOD))%MOD;
            b>>=1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = depth(1,-1,adj); 

        return power(2,d-1);
    }
};