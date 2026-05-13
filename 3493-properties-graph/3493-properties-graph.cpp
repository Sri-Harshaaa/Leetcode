class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(rank[y_leader] < rank[x_leader]) parent[y_leader] = x_leader;
        else if(rank[y_leader] > rank[x_leader]) parent[x_leader] = y_leader;
        else {
            parent[x_leader] = y_leader;
            rank[y_leader]++;
        }
    }

    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(a.begin(), a.end());
        int count = 0;
        for(int num : b) {
            if(setA.erase(num)) count++;
        }
        return count;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int components = n;
        vector<int> rank(n,0), parent(n);
        for(int i=0; i<n; i++) {
            parent[i]=i;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(intersect(properties[i],properties[j]) >= k) {
                    int i_leader = find(i,parent);
                    int j_leader = find(j,parent);
                    if(i_leader != j_leader) {
                        Union(i,j,parent,rank);
                        components--;
                    }
                }
            }
        }
        return components;
    }
};