class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    bool solve(int a,int b, int threshold, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        visited[a][b] = true;
        if(a == m-1 && b == n-1) return true;

        for(int i=0; i<4; i++) {
            int x = a + dx[i];
            int y = b + dy[i];

            if(isValid(x,y,m,n) && !visited[x][y] && grid[x][y] <= threshold) {
                if(solve(x,y,threshold,grid,visited)) return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int max = INT_MIN;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > max) max = grid[i][j];
            }
        }

        int l = 0, r = max, ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            vector<vector<bool>> visited(m, vector<bool>(n,false));
            if(grid[0][0] <= mid && solve(0,0,mid,grid,visited)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};