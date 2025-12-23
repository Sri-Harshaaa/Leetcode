class Solution {
public:
    bool isCycle(vector<vector<int>>& adj,int& u,vector<bool>& visited, vector<bool>& recStack) {
        visited[u] = true;
        recStack[u] = true;
        for(int &v : adj[u]) {
            if(visited[v] && recStack[v]) return true;
            else if(!visited[v]) {
                if(isCycle(adj,v,visited,recStack)) return true;
            }
        }
        recStack[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> visited(numCourses), recStack(numCourses);
        for(int i=0; i<numCourses; i++) {
            if(!visited[i] && isCycle(adj,i,visited,recStack)) return false;
        }
        return true;
    }
};