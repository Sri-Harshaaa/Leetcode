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

        if(rank[x_leader] < rank[y_leader]) parent[x_leader] = y_leader;
        else if(rank[y_leader] < rank[x_leader]) parent[y_leader] = x_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n+1), rank(n+1,0);
        for(int i=0; i<n+1; i++) {
            parent[i] = i;
        }

        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            Union(u,v,parent,rank);
        }

        for(int i=1; i<n+1; i++) {
            find(i,parent);
        }

        int leader = parent[1];

        int ans = INT_MAX;

        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            int u_leader = find(u,parent);
            int v_leader = find(v,parent);

            if(u_leader != leader || v_leader != leader) continue;

            ans = min(ans,w);
        }

        return ans;
    }
};