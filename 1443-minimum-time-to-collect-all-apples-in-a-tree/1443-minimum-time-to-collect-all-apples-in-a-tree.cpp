class Solution {
public:
    bool solve(int u, int& time, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        time++;
        bool flag = false;

        for(int& v : adj[u]) {
            if(v != parent && solve(v,time,u,adj,hasApple)) flag = true;
        }

        if(u !=0 && (hasApple[u] || flag)) {
            time++;
            return true;
        }
        else time--;

        return false;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int time = 0;
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(0,time,-1,adj,hasApple);
        return time;
    }
};