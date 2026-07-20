class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int a = k-(n-1-j);
                int u = a>0 ? (i+((a+n-1)/n))%m : i;
                int v = (j+k)%n;
                ans[u][v] = grid[i][j];
            }
        }

        return ans;
    }
};