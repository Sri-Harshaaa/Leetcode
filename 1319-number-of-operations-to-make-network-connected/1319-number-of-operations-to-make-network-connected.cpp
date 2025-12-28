class Solution {
public:
    void Union(int x,int y,vector<int>& parent,vector<int>& rank) {
        int leader_x = find(x,parent);
        int leader_y = find(y,parent);
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

    void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited) {
        visited[u] = true;
        for(int &v : adj[u]) {
            if(!visited[v]) DFS(adj,v,visited);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int E = connections.size();
        vector<int> parent(n), rank(n,0);
        for(int i=0; i<n; i++) parent[i] = i;
        if(E < n-1) return -1;

        int spare = 0;
        for(int i=0; i<E; i++) {
            int leader_x = find(connections[i][0],parent);
            int leader_y = find(connections[i][1],parent);
            if(leader_x == leader_y) spare++;
            else Union(connections[i][0],connections[i][1],parent,rank);
        }

        vector<vector<int>> adj(n);
        for(int i=0; i<E; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int comp = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                comp++;
                DFS(adj,i,visited);
            }
        }

        if(spare < comp-1) return -1;
        else return comp-1;
    }
};