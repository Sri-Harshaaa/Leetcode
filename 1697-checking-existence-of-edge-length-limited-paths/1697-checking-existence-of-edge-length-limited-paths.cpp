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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int e = edgeList.size();
        int q = queries.size();

        for(int i=0; i<q; i++) {
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        
        vector<int> parent(n), rank(n,0);
        vector<bool> ans(q);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int i = 0, j = 0;

        while(j < q) {
            int src = queries[j][0];
            int dst = queries[j][1];
            int limit = queries[j][2];
            int oi = queries[j][3];

            while(i < e) {
                int u = edgeList[i][0];
                int v = edgeList[i][1];
                int w = edgeList[i][2];

                if(w >= limit) break;

                Union(u,v,parent,rank);
                i++;
            }

            int src_leader = find(src,parent);
            int dst_leader = find(dst,parent);

            if(src_leader == dst_leader) ans[oi] = true;
            else ans[oi] = false;

            j++;
        }

        return ans;
    }
};