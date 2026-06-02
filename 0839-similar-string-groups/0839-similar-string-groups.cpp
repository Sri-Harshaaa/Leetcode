class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i], parent);
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

    bool isValid(string x, string y) {
        int cnt = 0;
        for(int i=0; i<x.size(); i++) {
            if(x[i] != y[i]) {
                cnt++;
                if(cnt > 2) return false;
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n), rank(n,26);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<n; i++) {
            string x = strs[i];
            for(int j=i+1; j<n; j++) {
                string y = strs[j];
                if(isValid(x,y)) Union(i,j,parent,rank);
            }
        }

        for(int i=0; i<n; i++) {
            find(i,parent);
        }

        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(parent[i]);
        }

        return st.size();
    }
};