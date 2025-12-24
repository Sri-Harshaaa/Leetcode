class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, int& u, vector<int>& ans, vector<bool>& visited, vector<bool>& recStack) {
        visited[u] = true;
        recStack[u] = true;
        for(int &v : adj[u]) {
            if(visited[v] && recStack[v]) return true;
            else if(!visited[v] && isCycle(adj,v,ans,visited,recStack)) return true;
        }
        ans.push_back(u);
        recStack[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> ans;
        vector<bool> visited(numCourses),recStack(numCourses);
        for(int i=0; i<numCourses; i++) {
            if(!visited[i] && isCycle(adj,i,ans,visited,recStack)) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};