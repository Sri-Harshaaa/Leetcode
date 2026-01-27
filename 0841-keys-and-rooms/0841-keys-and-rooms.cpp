class Solution {
public:
    void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(!visited[v]) {
                dfs(v,visited,adj);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), comp = 0;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                comp++;
                dfs(i,visited,rooms);
            }
        }
        return comp==1 ? true : false;
    }
};