class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist[node] < d) continue;

            for(auto& neighbr : adj[node]) {
                int v = neighbr.first;
                int w = neighbr.second;

                if(d+w < dist[v]) {
                    dist[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }
        int min_t = 0;

        for(int i=1; i<n+1; i++) {
            if(dist[i] == INT_MAX) return -1;
            if(dist[i] > min_t) min_t = dist[i];
        }
        return min_t;
    }
};