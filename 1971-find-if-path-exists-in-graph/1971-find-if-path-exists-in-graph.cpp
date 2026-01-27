class Solution {
public:
    bool dfs(int u, int des, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;
        if(u == des) return true;

        for(int& v : adj[u]) {
            if(!visited[v]) {
                if(dfs(v,des,visited,adj)) return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(source,destination,visited,adj);
    }
};