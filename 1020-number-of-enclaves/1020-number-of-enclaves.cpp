class Solution {
public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = 0;

        for(int k=0; k<4; k++) {
            int u = i + dx[k];
            int v = j + dy[k];
            if(isValid(u,v,m,n) && grid[u][v] != 0) {
                grid[u][v] = 0;
                dfs(u,v,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            if(grid[i][0] == 1) dfs(i,0,grid);
            if(grid[i][n-1] == 1) dfs(i,n-1,grid);
        }
        for(int j=1; j<n-1; j++) {
            if(grid[0][j] == 1) dfs(0,j,grid);
            if(grid[m-1][j] == 1) dfs(m-1,j,grid);
        }
        int count = 0;
        for(int i=1; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};