class Solution {
public:
    void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(!visited[v]) dfs(v,visited,adj);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<vector<bool>> reachable;

        for(int i=0; i<numCourses; i++) {
            vector<bool> visited(numCourses,false);
            dfs(i,visited,adj);

            reachable.push_back(visited);
        }

        vector<bool> ans(queries.size());

        for(int i=0; i<queries.size(); i++) {
            int src = queries[i][0];
            int dst = queries[i][1];
            vector<bool> visited(numCourses,false);

            if(reachable[src][dst]) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};