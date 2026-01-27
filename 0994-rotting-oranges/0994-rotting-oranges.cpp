class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i<m && i>=0 && j>=0 && j<n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int r_oranges = 0, f_oranges = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    r_oranges++;
                    q.push({{i,j}, 0});
                }
                else if(grid[i][j] == 1) f_oranges++;
            }
        }
        if(r_oranges == 0) {
            if(f_oranges!=0) return -1;
            else return 0;
        }

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        int min = -1;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int t = it.second;
            min = t;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(isValid(u,v,m,n) && grid[u][v]==1) {
                    q.push({{u,v}, t+1});
                    f_oranges--;
                    grid[u][v] = 2;
                }
            }
        }
        
        return f_oranges == 0 ? min : -1;
    }
};