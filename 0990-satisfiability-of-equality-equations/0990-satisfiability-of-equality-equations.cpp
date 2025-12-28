class Solution {
public:
    void Union(int x,int y,vector<int>& parent,vector<int>& rank) {
        int leader_x = find(x,parent);
        int leader_y = find(y,parent);
        if(leader_x == leader_y) return;
        
        if(rank[leader_x] > rank[leader_y]) parent[leader_y] = leader_x;
        else if(rank[leader_x] < rank[leader_y]) parent[leader_x] = leader_y;
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

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> parent(26), rank(26,0);
        for(int i=0; i<26; i++) parent[i] = i;
        for(int i=0; i<n; i++) {
            int node_1 = equations[i][0]-'a';
            int node_2 = equations[i][3]-'a';
            if(equations[i][1] == '=') Union(node_1,node_2,parent,rank);
        }
        for(int i=0; i<n; i++) {
            int node_1 = equations[i][0]-'a';
            int node_2 = equations[i][3]-'a';
            if(equations[i][1] == '!') {
                int leader_1 = find(node_1,parent);
                int leader_2 = find(node_2,parent);
                if(leader_1 == leader_2) return false;
            }
        }
        return true;
    }
};