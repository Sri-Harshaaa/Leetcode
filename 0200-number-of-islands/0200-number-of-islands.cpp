class Solution {
public:
    int m,n;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[x][y] = true;

        for(int i=0; i<4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];

            if(isValid(u,v,m,n) && grid[u][v] != '0' && !visited[u][v]) {
                dfs(u,v,visited,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i,j,visited,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};