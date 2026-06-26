class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(rank[x_leader] < rank[y_leader]) parent[x_leader] = y_leader;
        else if(rank[y_leader] < rank[x_leader]) parent[y_leader] = x_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> parent(e+1), rank(e+1,0), inDeg(e+1,0);
        int temp = -1;

        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            inDeg[v]++;
            if(inDeg[v]==2) temp = v;
        }
        
        for(int i=0; i<e+1; i++) {
            parent[i] = i;
        }

        if(temp != -1) {
            vector<int> c;

            for(int i=0; i<e; i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                if(v == temp) c.push_back(i); 
            }

            for(int i=0; i<e; i++) {
                if(i == c[1]) continue;
                int u = edges[i][0];
                int v = edges[i][1];

                int u_leader = find(u,parent);
                int v_leader = find(v,parent);
                if(u_leader == v_leader) return edges[c[0]];
                else Union(u,v,parent,rank);
            }
            return edges[c[1]];
        }

        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int u_leader = find(u,parent);
            int v_leader = find(v,parent);

            if(u_leader == v_leader) return {u,v};
            else Union(u,v,parent,rank);
        }

        return {};
    }
};