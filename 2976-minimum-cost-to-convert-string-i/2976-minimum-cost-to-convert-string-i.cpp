class Solution {
public:
    long long dijkstra(int source, int des, vector<vector<pair<int,long long>>>& adj) {
        vector<int> dist(26, INT_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[source] = 0;
        pq.push({0,source});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            int u = it.second;

            if(d > dist[u]) continue;
            for(auto& neighbr : adj[u]) {
                int v = neighbr.first;
                long long w = neighbr.second;
                if(d+w < dist[v]) {
                    pq.push({d+w,v});
                    dist[v] = d+w;
                }
            }
        } 
        return dist[des];
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,long long>>> adj(26);
        vector<vector<int>> dist(26, vector<int>(26, -1));
        for(int i=0; i<original.size(); i++) {
            int u = original[i]-'a';
            int v = changed[i] - 'a';
            long long w = cost[i];
            adj[u].push_back({v,w});
        }
        long long min_cost = 0;
        for(int i=0; i<source.size(); i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i]-'a';
                if(dist[u][v] == -1) {
                    dist[u][v] = dijkstra(u,v,adj);
                }
                if(dist[u][v] == INT_MAX) return -1;
                else min_cost+=dist[u][v];
            }
        }
        return min_cost;
    }
};