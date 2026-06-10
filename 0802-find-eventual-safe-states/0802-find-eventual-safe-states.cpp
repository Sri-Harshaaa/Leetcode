class Solution {
public:
    bool dfs(int u, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& graph) {
        visited[u] = true;
        recStack[u] = true;

        for(int v : graph[u]) {
            if(!visited[v] && dfs(v,visited,recStack,graph)) return true;
            else if(recStack[v]) return true;
        }

        recStack[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<bool> visited(n,false),recStack(n,false);
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) dfs(i,visited,recStack,graph);
        }

        for(int i=0; i<n; i++) {
            if(!recStack[i]) ans.push_back(i);
        }

        return ans;
    }
};