class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& rank, vector<int>& parent) {
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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> rank(n,0), parent(n);
        unordered_map<int,int> col,row;

        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<stones.size(); i++) {
            int a = stones[i][0];
            int b = stones[i][1];
            
            if(row.contains(a)) Union(row[a],i,rank,parent);
            if(col.contains(b)) Union(col[b],i,rank,parent);

            row[a] = i;
            col[b] = i;
        }

        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(find(i,parent));
        }
        
        return n-st.size();
    }
};