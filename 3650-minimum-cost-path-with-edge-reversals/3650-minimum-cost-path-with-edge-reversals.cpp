class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int d = it.first;

            if(d > dist[u]) continue;
            for(auto& neighbr : adj[u]) {
                int v = neighbr.first;
                int w = neighbr.second;
                if(d+w < dist[v]) {
                    pq.push({d+w,v});
                    dist[v] = d+w;
                }
            }
        }
        return dist[n-1]!=INT_MAX ? dist[n-1] : -1;
    }
};