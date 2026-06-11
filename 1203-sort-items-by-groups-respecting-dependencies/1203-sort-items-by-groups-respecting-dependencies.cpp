class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDeg(n,0);

        for(int i=0; i<n; i++) {
            for(int& v : graph[i]) {
                inDeg[v]++;
            }
        }

        queue<int> q;
        vector<int> order;

        for(int i=0; i<n; i++) {
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for(int& v : graph[u]) {
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }

        if(order.size() != n) return {};

        return order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int g = m;
        for(int i=0; i<group.size(); i++) {
            if(group[i] == -1) {
                group[i] = g;
                g++;
            }
        }

        vector<vector<int>> items(n), groups(g);
        set<pair<int,int>> st;

        for(int i=0; i<beforeItems.size(); i++) {
            int ug = group[i];
            for(int j=0; j<beforeItems[i].size(); j++) {
                int v = beforeItems[i][j];
                int vg = group[v];
                items[v].push_back(i);
                if(ug != vg && !st.count({vg,ug})) {
                    st.insert({vg,ug});
                    groups[vg].push_back(ug);
                }
            }
        }

        vector<int> groups_order = topoSort(groups);
        vector<int> items_order = topoSort(items);

        if(groups_order.empty() || items_order.empty()) return {};

        vector<vector<int>> colours(g);

        for(int i=0; i<n; i++) {
            int item = items_order[i];
            int colour = group[item];
            colours[colour].push_back(item);
        }

        vector<int> ans;

        for(int i=0; i<g; i++) {
            int colour = groups_order[i];
            if(colours[colour].empty()) continue;

            for(int& v : colours[colour]) {
                ans.push_back(v);
            }
        }

        return ans;
    }
};