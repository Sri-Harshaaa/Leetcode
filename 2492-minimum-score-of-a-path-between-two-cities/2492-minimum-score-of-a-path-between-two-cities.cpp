class Solution {
public:
    void dfs(int u, int& ans, vector<bool>& visited, vector<vector<pair<int,int>>>& adj) {
        visited[u] = true;

        for(auto& neighbr : adj[u]) {
            int v = neighbr.first;
            int w = neighbr.second;

            ans = min(ans,w);

            if(!visited[v]) dfs(v,ans,visited,adj);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int ans = INT_MAX;
        vector<bool> visited(n+1,false);

        dfs(1,ans,visited,adj);

        return ans;
    }
};