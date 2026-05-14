class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;

        return gcd(b, a % b);
    }

    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(x_leader == y_leader) return;

        if(rank[x_leader] < rank[y_leader]) parent[x_leader] = y_leader;
        else if(rank[x_leader] > rank[y_leader]) parent[y_leader] = x_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> rank(n+1,0), parent(n+1);

        for(int i=0; i<n+1; i++) parent[i] = i;

        for(int i = threshold+1; i <= n; i++) {
            for(int j = 2*i; j <= n; j += i) {
                Union(i, j,parent,rank);
            }
        }

        for(int i=0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            
            int a_leader = find(a,parent);
            int b_leader = find(b,parent);
            if(a_leader == b_leader) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};