class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(x_leader == y_leader) return;

        if(rank[y_leader] > rank[x_leader]) parent[x_leader] = y_leader;
        else if(rank[x_leader] > rank[y_leader]) parent[y_leader] = x_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> parent(n), rank(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[vals[i]].push_back(i);
        }

        vector<bool> active(n,false);
        int ans = 0;

        for(auto it : mpp) {
            vector<int> nodes = it.second;
            for(int& u : nodes) {
                active[u] = true;
                for(int& v : adj[u]) {
                    if(active[v]) Union(u,v,parent,rank);
                }
            }

            vector<int> temp;
            for(int& u : nodes) {
                int par = find(u,parent);
                temp.push_back(par);
            }
            unordered_map<int,int> freq;
            for(int i=0; i<temp.size(); i++) {
                freq[temp[i]]++;
            }
            for(auto it : freq) {
                int cnt = it.second;
                if(cnt <= 1) continue;
                else ans+=((cnt*(cnt-1))/2);
            }
        }
        return ans+n;
    }
};