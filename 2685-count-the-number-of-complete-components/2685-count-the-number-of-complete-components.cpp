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

        if(rank[y_leader] < rank[x_leader]) parent[y_leader] = x_leader;
        else if(rank[x_leader] < rank[y_leader]) parent[x_leader] = y_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> outDeg(n,0);
        vector<int> parent(n), rank(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            Union(u,v,parent,rank);
            outDeg[u]++;
            outDeg[v]++;
        }

        for(int i=0; i<n; i++) {
            find(i,parent);
        }

        unordered_map<int,vector<int>> mpp;

        for(int i=0; i<n; i++) {
            mpp[parent[i]].push_back(i);
        }

        int cnt = 0;

        for(auto& it : mpp) {
            int m = it.second.size();
            bool flag = true;
            for(int i=0; i<m; i++) {
                if(outDeg[it.second[i]] != m-1) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }

        return cnt;
    }
};