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

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q);
        vector<int> parent(n), rank(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=1; i<n; i++) {
            if(abs(nums[i]-nums[i-1]) <= maxDiff) Union(i,i-1,parent,rank);
        }

        for(int i=0; i<q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            int u_leader = find(u,parent);
            int v_leader = find(v,parent);

            if(u_leader == v_leader) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};