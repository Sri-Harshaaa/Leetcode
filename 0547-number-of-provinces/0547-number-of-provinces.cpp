class Solution {
public:
    void runBFS(vector<vector<int>>& adj,int u,vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(int i=0; i<adj.size(); i++) {
                if(adj[top][i]==1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int v = isConnected.size();
        vector<bool> visited(v);
        for(int i=0; i<v; i++) {
            if(!visited[i]) {
                provinces++;
                runBFS(isConnected,i,visited);
            }
        }
        return provinces;
    }
};