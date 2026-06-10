class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = INT_MIN;
        vector<set<int>> adj(n);
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int cnt = adj[i].size() + adj[j].size();
                if(adj[i].count(j)) cnt--;
                ans = max(ans,cnt);
            }
        }

        return ans;
    }
};