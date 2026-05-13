class Solution {
public:
    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(a.begin(), a.end());
        int count = 0;
        for(int num : b) {
            if(setA.erase(num)) count++;
        }
        return count;
    }

    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;

        for(int &v: adj[u]) {
            if(!visited[v]) dfs(v,adj,visited);
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int components = 0;
        vector<int> rank(n,0), parent(n);
        for(int i=0; i<n; i++) {
            parent[i]=i;
        }
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(intersect(properties[i],properties[j]) >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n,false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i,adj,visited);
                components++;
            }
        }
        return components;
    }
};