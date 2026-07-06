class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {-1,0};
        vector<int> dy = {0,-1};
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];

        for(int x=0; x<m; x++) {
            for(int y=0; y<n; y++) {
                if(x==0 && y==0) continue;

                for(int i=0; i<2; i++) {
                    int u = x + dx[i];
                    int v = y + dy[i];

                    if(isValid(u,v,m,n) && dist[u][v] != INT_MAX) {
                        dist[x][y] = min(dist[x][y], dist[u][v]+grid[x][y]);
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};