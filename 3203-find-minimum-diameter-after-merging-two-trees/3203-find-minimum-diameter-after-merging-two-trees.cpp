class Solution {
public:
    pair<int,int> bfs(int u, vector<vector<int>>& adj) {
        int V = adj.size();
        queue<int> q;
        vector<bool> visited(V, false);
        int d = 0, x = -1;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int node = q.front();
                x = node;
                q.pop();
                for(int& v : adj[node]) {
                    if(!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            d++;
        }
        return {x,d};
    }

    int diameter(vector<vector<int>>& adj) {
        int u = 0;
        int a = bfs(u,adj).first;
        int d = bfs(a,adj).second;
        return d;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int e1 = edges1.size(), e2 = edges2.size();
        vector<vector<int>> adj1(e1+1), adj2(e2+1);
        for(int i=0; i<e1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i=0; i<e2; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        float d1 = diameter(adj1)-1;
        float d2 = diameter(adj2)-1;
        
        int ans = ceil(d1/2)+ceil(d2/2)+1;
        int max_d = max(d1,d2);
        return max(max_d, ans);
    }
};