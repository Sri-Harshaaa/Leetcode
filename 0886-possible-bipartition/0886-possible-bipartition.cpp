class Solution {
public:
    bool isBipartite(int src, vector<int>& colour, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> q;
        colour[src] = 1;
        q.push(src);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v: adj[u]) {
                if(colour[v] == -1) {
                    colour[v] = 1 - colour[u];
                    q.push(v);
                }
                else if(colour[v] == colour[u]) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        vector<int> colour(n, -1);

        for(int i=0; i<dislikes.size(); i++) {
            int u = dislikes[i][0]-1;
            int v = dislikes[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<n; i++) {
            if(colour[i] == -1 && !isBipartite(i,colour,adj)) return false; 
        }
        
        return true;
    }
};