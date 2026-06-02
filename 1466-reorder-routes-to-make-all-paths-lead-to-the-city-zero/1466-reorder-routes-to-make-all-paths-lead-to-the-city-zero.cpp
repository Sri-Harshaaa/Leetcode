class Solution {
public:
    void dfs(int u, int& count, vector<bool>& visited, vector<vector<pair<int,int>>>& adj) {
        visited[u] = true;

        for(auto& neighbr : adj[u]) {
            int v = neighbr.first;
            int w = neighbr.second;

            if(!visited[v]) {
                if(w == 1) count++;
                dfs(v,count,visited,adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        
        int count = 0;
        vector<bool> visited(n,false);

        dfs(0,count,visited,adj);

        return count;
    }
};