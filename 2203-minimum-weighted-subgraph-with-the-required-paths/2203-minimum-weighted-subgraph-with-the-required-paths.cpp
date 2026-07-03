class Solution {
public:
    vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {
            pair<long long,int> p = pq.top();
            pq.pop();
            long long d = p.first;
            int u = p.second;

            if(d > dist[u]) continue;

            for(auto& neighbr : adj[u]) {
                int v = neighbr.first;
                long long w = neighbr.second;

                if(d+w < dist[v]) {
                    dist[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        int e = edges.size();
        vector<vector<pair<int,int>>> adj(n), radj(n);
        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            radj[v].push_back({u,w});
        }  

        vector<long long> dist1 = dijkstra(src1,adj);
        vector<long long> dist2 = dijkstra(src2,adj);
        vector<long long> dist = dijkstra(dest,radj);

        long long ans = LLONG_MAX;

        for(int i=0; i<n; i++) {
            long long x = dist1[i];
            long long y = dist2[i];
            long long z = dist[i];

            if(x==LLONG_MAX || y==LLONG_MAX || z==LLONG_MAX) continue;

            ans = min(ans,x+y+z);
        }

        return ans==LLONG_MAX ? -1 : ans;
    }
};