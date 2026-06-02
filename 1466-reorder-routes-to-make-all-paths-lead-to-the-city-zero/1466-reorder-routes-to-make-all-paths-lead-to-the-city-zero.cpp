class Solution {
public:
    void dfs(int u, int& count, set<pair<int,int>>& st, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(!visited[v]) {
                if(!st.count({v,u})) count++;
                dfs(v,count,st,visited,adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int,int>> st;

        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            st.insert({u,v});
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count = 0;
        vector<bool> visited(n,false);

        dfs(0,count,st,visited,adj);

        return count;
    }
};