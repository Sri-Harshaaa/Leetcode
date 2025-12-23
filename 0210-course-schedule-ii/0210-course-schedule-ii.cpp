class Solution {
public:
    void topoSort(vector<vector<int>>& adj, vector<int>& ans, vector<int>& inDeg) {
        queue<int> q;
        for(int i=0; i<inDeg.size(); i++) {
            if(inDeg[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for(int &v : adj[top]) {
                inDeg[v]--;
                if(inDeg[v]==0) q.push(v);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> inDeg(numCourses);
        for(auto &neighbours : adj) {
            for(int &v : neighbours) {
                inDeg[v]++;
            }
        }
        vector<int> ans;
        topoSort(adj,ans,inDeg);
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};