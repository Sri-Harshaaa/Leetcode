class Solution {
public:
    bool dijkstra(int src, int des, int threshold, int k, vector<vector<pair<int,int>>> adj) {
        int n = adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &neighbr: adj[u]) {
                int v = neighbr.first;
                int w = neighbr.second;
                neighbr.second = (w > threshold) ? 1 : 0;
                w = neighbr.second;

                if(d+w < dist[v]) {
                    dist[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }
        
        return dist[des] != INT_MAX && dist[des] <= k ? true : false;
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int l = 0, r = 1e9;
        int threshold = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            bool flag = dijkstra(source,target,mid,k,adj);

            if(flag) {
                threshold = mid;
                 r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return threshold;
    }
};