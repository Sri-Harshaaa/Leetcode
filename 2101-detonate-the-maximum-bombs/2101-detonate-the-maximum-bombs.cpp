class Solution {
public:
    int dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;
        int cnt = 1;

        for(int& v : adj[u]) {
            if(!visited[v]) cnt+=dfs(v,visited,adj);
        }

        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];

            for(int j=0; j<n; j++) {
                if(j==i) continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];

                if(1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2) <= 1LL*r*r) adj[i].push_back(j);
            }
        }

        int count = INT_MIN;

        for(int i=0; i<n; i++) {
            vector<bool> visited(n,false);
            int ans = dfs(i,visited,adj);
            count = max(count,ans);
        }

        return count;
    }
};