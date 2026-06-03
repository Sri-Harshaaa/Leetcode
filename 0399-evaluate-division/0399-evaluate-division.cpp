class Solution {
public:
    double dfs(string src, string target, unordered_map<string,bool>& visited, unordered_map<string,vector<pair<string,double>>>& adj) {
        visited[src] = true;
        if(src == target) return 1.0;

        for(auto& neighbr : adj[src]) {
            string v = neighbr.first;
            double w = neighbr.second;

            if(!visited[v]) {
                double val = dfs(v,target,visited,adj);
                if(val != -1) return val*w;
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int q = queries.size();
        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i=0; i<equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,1/w});
        }

        vector<double> ans(q);

        for(int i=0; i<q; i++) {
            string x = queries[i][0];
            string y = queries[i][1];

            if(!adj.count(x) || !adj.count(y)) {
                ans[i] = -1;
                continue;
            }

            unordered_map<string,bool> visited;

            for(auto& it : adj) {
                visited[it.first] = false;
            }

            double sol = dfs(x,y,visited,adj);
            ans[i] = sol;
        }

        return ans;
    }
};