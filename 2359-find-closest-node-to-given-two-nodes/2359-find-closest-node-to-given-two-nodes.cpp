class Solution {
public:
    vector<int> bfs(int u, vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        dist[u] = 0;
        visited[u] = true;
        queue<int> q;
        q.push(u);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            int v = edges[node];
            if(v == -1) continue;

            if(!visited[v]) {
                dist[v] = dist[node] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> n1 = bfs(node1,edges);
        vector<int> n2 = bfs(node2,edges);

        int ans = INT_MAX, result = -1;

        for(int i=0; i<n; i++) {
            int sol = max(n1[i],n2[i]);
            if(sol < ans) {
                ans = sol;
                result = i;
            }
        }

        return result;
    }
};