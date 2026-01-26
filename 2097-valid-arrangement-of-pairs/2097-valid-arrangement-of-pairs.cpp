class Solution {
public:
    void DFS(int u, vector<int>& path, unordered_map<int,vector<int>>& adj) {
        auto& neighbrs = adj[u];

        while(!neighbrs.empty()) {
            int v = neighbrs.back();
            neighbrs.pop_back();
            DFS(v,path,adj);
        }
        path.push_back(u);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> inDeg, outDeg;
        for(int i=0; i<pairs.size(); i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        vector<int> path;
        int start_node = pairs[0][0];
        for(auto& it : adj) {
            int u = it.first;
            if(outDeg[u]-inDeg[u] == 1) {
                start_node = u;
                break;
            }
        }
        DFS(start_node,path,adj);
        reverse(path.begin(), path.end());

        vector<vector<int>> ans;
        for(int i=0; i<path.size()-1; i++) {
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};