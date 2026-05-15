class Solution {
public:
    using ll = long long;

    vector<ll> dijkstra(int u, vector<vector<pair<int,ll>>>& adj) {
        int n = adj.size();
        vector<ll> dist(n, INT_MAX);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[u] = 0;
        pq.push({0,u});

        while(!pq.empty()) {
            int node = pq.top().second;
            ll d = pq.top().first;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &neighbr: adj[node]) {
                int v = neighbr.first;
                ll w = neighbr.second;

                if(d+w < dist[v]) {
                    dist[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }
        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,ll>>> adj1(n), adj2(n);
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            ll w1 = roads[i][2];
            ll w2 = 1LL*roads[i][2]*roads[i][3];

            adj1[u].push_back({v,w1});
            adj1[v].push_back({u,w1});

            adj2[u].push_back({v,w2});
            adj2[v].push_back({u,w2});
        }

        vector<vector<ll>> go, come;

        for(int i=0; i<n; i++) {
            go.push_back(dijkstra(i,adj1));
            come.push_back(dijkstra(i,adj2));
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            ll mini = prices[i];
            for(int j=0; j<n; j++) {
                ll x = go[i][j] + prices[j] + come[j][i];
                mini = min(x,mini);
            }
            ans.push_back(mini);
        }
        
        return ans;
    }
};