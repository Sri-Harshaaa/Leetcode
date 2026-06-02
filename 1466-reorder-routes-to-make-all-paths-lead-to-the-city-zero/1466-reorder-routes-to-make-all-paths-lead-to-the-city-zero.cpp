class Solution {
public:
    void dfs(int u, int& count, int parent, vector<vector<pair<int,int>>>& adj) {
        for(auto& neighbr : adj[u]) {
            int v = neighbr.first;
            int w = neighbr.second;

            if(v != parent) {
                if(w == 1) count++;
                dfs(v,count,u,adj);
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
  
        dfs(0,count,-1,adj);

        return count;
    }
};