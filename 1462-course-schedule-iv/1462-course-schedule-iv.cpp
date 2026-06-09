class Solution {
public:
    bool dfs(int src, int target, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[src] = true;
        if(src == target) return true;

        for(int& v : adj[src]) {
            if(!visited[v] && dfs(v,target,visited,adj)) return true;
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<bool> ans(queries.size());

        for(int i=0; i<queries.size(); i++) {
            int src = queries[i][0];
            int dst = queries[i][1];
            vector<bool> visited(numCourses,false);

            if(dfs(src,dst,visited,adj)) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};