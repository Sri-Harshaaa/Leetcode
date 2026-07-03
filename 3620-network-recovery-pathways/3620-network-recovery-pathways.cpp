class Solution {
public:
    void topoSort(int u, vector<bool>& visited, vector<vector<pair<int,long long>>>& adj, vector<int>& order) {
        visited[u] = true;

        for(auto& neighbr : adj[u]) {
            int v = neighbr.first;

            if(!visited[v]) topoSort(v,visited,adj,order);
        }

        order.push_back(u);
    }

    bool valid(long long mini, long long k, vector<int>& order, vector<vector<pair<int,long long>>>& adj) {
        int n =adj.size();
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;

        for(int i=0; i<n; i++) {
            int u = order[i];

            if(dist[u] == LLONG_MAX) continue;

            for(auto& neighbr : adj[u]) {
                int v = neighbr.first;
                long long w = neighbr.second;
                if(w < mini) continue;

                dist[v] = min(dist[v],dist[u]+w);
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int e = edges.size();
        int n = online.size();
        vector<vector<pair<int,long long>>> adj(n);
        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];
            if(w > k) continue;

            if(online[u] && online[v]) adj[u].push_back({v,w});
        }

        vector<int> order;
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) topoSort(i,visited,adj,order);
        }
        reverse(order.begin(), order.end());

        long long l = 0, h = k;
        long long ans = -1;

        while(l<=h) {
            long long mid = l + (h-l)/2;
            if(valid(mid,k,order,adj)) {
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }

        return ans;
    }
};