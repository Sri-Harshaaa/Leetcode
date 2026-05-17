class Solution {
public:
    bool dfs(int u, vector<int>& arr, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;
        if(arr[u] == 0) return true;

        for(int &v: adj[u]) {
            if(!visited[v] && dfs(v,arr,visited,adj)) return true;
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            if(n > i+arr[i] && arr[i] != 0) adj[i].push_back(i+arr[i]);
            if(i-arr[i] >= 0 && arr[i] != 0) adj[i].push_back(i-arr[i]);
        }
        vector<bool> visited(n, false);

        return dfs(start,arr,visited,adj);
    }
};