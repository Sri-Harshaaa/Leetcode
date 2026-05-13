class Solution {
public:
    bool solve(int u, vector<vector<int>>& adj, int currColour, vector<int>& colour) {
        colour[u] = currColour;

        for(int &v : adj[u]) {
            if(colour[v] == -1) {
                if(!solve(v,adj,1-currColour,colour)) return false ;
            }
            else if(currColour == colour[v]) return false;
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