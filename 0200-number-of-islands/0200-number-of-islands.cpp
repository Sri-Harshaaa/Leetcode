class Solution {
public:
    int m,n;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    void bfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        visited[x][y] = true;
        q.push({x,y});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x1 = p.first;
            int y1 = p.second;

            for(int i=0; i<4; i++) {
            int u = x1 + dx[i];
            int v = y1 + dy[i];

            if(isValid(u,v,m,n) && grid[u][v] != '0' && !visited[u][v]) {
                    visited[u][v] = true;
                    q.push({u,v});
                }
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
                    bfs(i,j,visited,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};