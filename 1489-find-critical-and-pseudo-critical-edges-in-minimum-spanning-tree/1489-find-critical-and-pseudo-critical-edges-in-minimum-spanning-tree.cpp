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

    int find_MST(int skip, int force, int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> parent(n), rank(n,0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int cost = 0;
        int edge_count = 0;

        if(force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];
            Union(u,v,parent,rank);
            cost+=w;
            edge_count++;
        }

        for(int i=0; i<e; i++) {
            if(i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int u_leader = find(u,parent);
            int v_leader = find(v,parent);

            if(u_leader != v_leader) {
                Union(u,v,parent,rank);
                cost+=w;
                edge_count++;
            } 
        }

        return edge_count == n-1 ? cost : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> ans;
        vector<int> ce, pce;

        for(int i=0; i<e; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int cost = find_MST(-1,-1,n,edges);

        for(int i=0; i<e; i++) {
            int new_cost = find_MST(i,-1,n,edges);

            if(new_cost > cost) ce.push_back(edges[i][3]);
            else if(find_MST(-1,i,n,edges) == cost) pce.push_back(edges[i][3]);
        }

        sort(ce.begin(), ce.end());
        sort(pce.begin(), pce.end());

        ans.push_back(ce);
        ans.push_back(pce);

        return ans;
    }
};