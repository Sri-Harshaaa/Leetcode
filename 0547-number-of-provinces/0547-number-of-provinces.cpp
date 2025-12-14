class Solution {
public:
    void runDFS(vector<vector<int>>& adj,int u,vector<bool>& visited) {
        visited[u] = true;
        for(int i=0; i<adj.size(); i++) {
            if(adj[u][i]==1  && !visited[i]) runDFS(adj,i,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int v = isConnected.size();
        vector<bool> visited(v,false);
        for(int i=0; i<v; i++) {
            if(!visited[i]) {
                provinces++;
                runDFS(isConnected,i,visited);
            }
        }
        return provinces;
    }
};