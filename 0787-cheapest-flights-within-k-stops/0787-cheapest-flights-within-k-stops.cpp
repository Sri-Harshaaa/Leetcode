class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v,w});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.push({src,0});
        int level = 0;

        while(!q.empty() && level <= k) {
            int m = q.size();

            while(m--) {
                auto it = q.front();
                q.pop();
                int u = it.first;
                int d = it.second;

                for(auto& neighbr : adj[u]) {
                    int v = neighbr.first;
                    int w = neighbr.second;

                    if(d+w < dist[v]) {
                        dist[v] = d+w;
                        q.push({v,d+w});
                    }
                }
            }
            level++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};