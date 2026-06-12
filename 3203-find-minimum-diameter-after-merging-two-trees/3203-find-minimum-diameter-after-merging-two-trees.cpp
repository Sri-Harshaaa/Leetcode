class Solution {
public:
    int diameter(int u, int parent, int& d, vector<vector<int>>& adj) {
        int m1 = 0, m2 = 0;

        for(int& v : adj[u]) {
            if(v == parent) continue;

            int sol = diameter(v,u,d,adj);
            if(sol > m1) {
                m2 = m1;
                m1 = sol;
            }
            else if(sol > m2) m2 = sol;
        }
        d = max(d, m1+m2);

        return m1+1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int e1 = edges1.size(), e2 = edges2.size();
        vector<vector<int>> adj1(e1+1), adj2(e2+1);
        for(int i=0; i<e1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i=0; i<e2; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int d1 = 0, d2 = 0;
        diameter(0,-1,d1,adj1);
        diameter(0,-1,d2,adj2);
        
        return max({d1,d2,(d1+1)/2+(d2+1)/2 +1 });
    }
};