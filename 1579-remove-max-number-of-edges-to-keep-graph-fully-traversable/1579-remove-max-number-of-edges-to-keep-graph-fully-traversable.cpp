class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(rank[y_leader] < rank[x_leader]) parent[y_leader] = x_leader;
        else if(rank[x_leader] < rank[y_leader]) parent[x_leader] = y_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> parent1(n+1), parent2(n+1);
        vector<int> rank1(n+1,0), rank2(n+1,0);

        for(int i=0; i<n+1; i++) {
            parent1[i] = i;
            parent2[i] = i;
        }

        int count = 0;

        for(int i=0; i<e; i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(type != 3) continue;

            if(find(u,parent1) == find(v,parent1)) count++;
            else {
                Union(u,v,parent1,rank1);
                Union(u,v,parent2,rank2);
            }
        }

        for(int i=0; i<e; i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(type == 3) continue;

            if(type == 1) {
                if(find(u,parent1) == find(v,parent1)) count++;
                else Union(u,v,parent1,rank1);
            }
            else {
                if(find(u,parent2) == find(v,parent2)) count++;
                else Union(u,v,parent2,rank2);
            }
        }

        for(int i=1; i<n+1; i++) {
            find(i,parent1);
            find(i,parent2);
        }

        for(int i=2; i<n+1; i++) {
            if((parent1[i] != parent1[i-1]) || (parent2[i] != parent2[i-1])) return -1;
        }

        return count;
    }
};