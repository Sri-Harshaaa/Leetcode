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

    int power(int a, int b) {
        if(b == 0) return 1;

        int half = power(a,b/2);
        int res = ((half%MOD)*(half%MOD))%MOD;
        if(b%2) return ((a%MOD)*(res%MOD))%MOD;
        else return res;
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