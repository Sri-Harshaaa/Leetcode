class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mpp;

        for(int i=0; i<n; i++) {
            mpp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        q.push(0);
        dist[0] = 0;
        visited[0] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            int v1 = u+1;
            int v2 = u-1;

            if(v1 < n && !visited[v1]) {
                visited[v1] = true;
                dist[v1] = dist[u]+1;
                q.push(v1);
            }
            if(v2 >= 0 && !visited[v2]) {
                visited[v2] = true;
                dist[v2] = dist[u]+1;
                q.push(v2);
            }
            for(int &v: mpp[arr[u]]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
            mpp.erase(arr[u]);
        }
        return dist[n-1];
    }
};