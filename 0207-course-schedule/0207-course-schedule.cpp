class Solution {
public:
    void topoSort(vector<vector<int>>& adj,int& courses,vector<int>& inDeg) {
        queue<int> q;
        for(int i=0; i<inDeg.size(); i++) {
            if(inDeg[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            courses++;
            for(int &v : adj[top]) {
                inDeg[v]--;
                if(inDeg[v]==0) q.push(v);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        int courses = 0;
        vector<int> inDeg(numCourses);
        for(auto &neighbr : adj) {
            for(int &v : neighbr) {
                inDeg[v]++;
            }
        }
        topoSort(adj,courses,inDeg);
        if(courses == numCourses) return true;
        else return false;
    }
};