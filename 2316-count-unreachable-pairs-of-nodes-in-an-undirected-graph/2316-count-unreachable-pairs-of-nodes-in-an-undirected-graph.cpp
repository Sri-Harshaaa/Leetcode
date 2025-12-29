class Solution {
public:
    void Union(int x,int y,vector<int>& parent,vector<int>& rank) {
        int leader_x = find(x,parent);
        int leader_y = find(y,parent);
        if(leader_x == leader_y) return;

        if(rank[leader_x] < rank[leader_y]) parent[leader_x] = leader_y;
        else if(rank[leader_x] > rank[leader_y]) parent[leader_y] = leader_x;
        else {
            parent[leader_x] = leader_y;
            rank[leader_y]++;
        }
        return;
    }

    int find(int i,vector<int>& parent) {
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i],parent);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n,0);
        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<edges.size(); i++) {
            Union(edges[i][0],edges[i][1],parent,rank);
        }

        vector<int> comp(n,0);
        for(int i=0; i<n; i++) {
            int x = find(i,parent);
            comp[x]++;
        }
        long long pre_sum = 0, ans = 0;
        for(int &v : comp) {
            ans+=v*pre_sum;
            pre_sum+=v;
        }
        return ans;
    }
};