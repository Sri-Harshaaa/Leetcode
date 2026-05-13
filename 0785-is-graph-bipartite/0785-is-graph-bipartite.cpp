class Solution {
public:
    bool solve(int u, vector<vector<int>>& adj, int currColour, vector<int>& colour) {
        queue<int> q;
        colour[u] = currColour;
        q.push(u);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int &v:adj[node]) {
                if(colour[v]==-1) {
                    colour[v] = 1-colour[node];
                    q.push(v);
                }
                else if(colour[v] == colour[node]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,-1);

        for(int i=0; i<n; i++) {
            if(colour[i]==-1 && !solve(i,graph,1,colour)) return false;
        }
        return true;
    }
};