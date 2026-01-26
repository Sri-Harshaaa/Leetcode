class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> inDeg, outDeg;
        for(int i=0; i<pairs.size(); i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        
        int start_node = pairs[0][0];
        for(auto& it : adj) {
            int u = it.first;
            if(outDeg[u]-inDeg[u] == 1) {
                start_node = u;
                break;
            }
        }
        
        vector<int> path;
        stack<int> st;
        st.push(start_node);
        while(!st.empty()) {
            int u = st.top();
            if(!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                st.push(v);
            }
            else {
                path.push_back(u);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());

        vector<vector<int>> ans;
        for(int i=0; i<path.size()-1; i++) {
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};