class Solution {
public:
    void bfs(int u, vector<int>& d, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int& v : adj[node]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    d[v] = d[node]+1;
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int e = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> X(n,0), Y(n,0), Z(n,0);
        bfs(x,X,adj);
        bfs(y,Y,adj);
        bfs(z,Z,adj);
        
        int spcl = 0;
        for(int i=0; i<n; i++) {
            int dx = X[i];
            int dy = Y[i];
            int dz = Z[i];
            vector<int> arr = {dx,dy,dz};
            sort(arr.begin(), arr.end());
            long long a = 1LL*arr[0]*arr[0]+1LL*arr[1]*arr[1], b = 1LL*arr[2]*arr[2];
            if(a == b) spcl++;
        }
        return spcl;
    }
};