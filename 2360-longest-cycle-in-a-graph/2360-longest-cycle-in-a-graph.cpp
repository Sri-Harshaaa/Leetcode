class Solution {
public:
    int dfs(int u, vector<int>& adj, vector<bool>& visited) {
        visited[u] = true;
        int cnt = 1;

        int v = adj[u];
        if(v != -1 && !visited[v]) cnt+=dfs(v,adj,visited);
    
        return cnt;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> inDeg(n,0);
        for(int i=0; i<n; i++) {
            if(edges[i] != -1) inDeg[edges[i]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            int v = edges[node];
            if(v != -1) {
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }

        vector<bool> visited(n,false);

        int ans = -1;
        for(int i=0; i<n; i++) {
            if(inDeg[i] && !visited[i]) {
                int x = dfs(i,edges,visited);
                ans = max(ans,x);
            }
        }
        return ans;
    }
};