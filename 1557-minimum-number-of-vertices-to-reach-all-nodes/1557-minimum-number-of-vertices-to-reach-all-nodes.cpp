class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n,0), ans;
        for(int i=0; i<edges.size(); i++) {
            inDeg[edges[i][1]]++;
        }

        for(int i=0; i<n; i++) {
            if(!inDeg[i]) ans.push_back(i);
        }

        return ans;
    }
};