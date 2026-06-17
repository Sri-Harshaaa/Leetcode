class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int e = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int city = -1, sol = INT_MAX;

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(dist[i][j] <= distanceThreshold) count++;
            }
            if(count <= sol) {
                sol = count;
                city = i;
            }
        }

        return city;
    }
};