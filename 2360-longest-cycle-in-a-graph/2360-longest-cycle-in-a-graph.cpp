class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        int cnt = 1;

        for(int &v: adj[u]) {
            if(!visited[v]) cnt+=dfs(v,adj,visited);
        }
        return cnt;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        vector<int> inDeg(n,0);
        for(int i=0; i<n; i++) {
            for(int &v: adj[i]) {
                inDeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int &v : adj[node]) {
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }

        vector<bool> visited(n,false);

        int ans = -1;
        for(int i=0; i<n; i++) {
            if(inDeg[i] && !visited[i]) {
                int x = dfs(i,adj,visited);
                ans = max(ans,x);
            }
        }
        return ans;
    }
};