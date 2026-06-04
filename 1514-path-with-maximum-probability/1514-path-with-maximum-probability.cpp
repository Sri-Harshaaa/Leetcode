class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0);
        dist[start_node] = 1;
        pq.push({1,start_node});

        while(!pq.empty()) {
            double d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(u == end_node) return dist[end_node];

            for(auto& neighbr : adj[u]) {
                int v = neighbr.first;
                double w = neighbr.second;

                if(dist[v] < d*w) {
                    dist[v] = d*w;
                    pq.push({d*w,v});
                }
            }
        }

        return dist[end_node];
    }
};