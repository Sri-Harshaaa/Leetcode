class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (k >= m + n - 2) return m + n - 2;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        queue<array<int,4>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MIN));
        dist[0][0] = grid[0][0] ? k-1 : k;
        q.push({0,0,dist[0][0],0});


        while(!q.empty()) {
            array<int,4> arr = q.front();
            q.pop();
            int x = arr[0];
            int y = arr[1];
            int h = arr[2];
            int steps = arr[3];

            if(x == m-1 && y == n-1) return steps;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(u==m-1 && v==n-1) return steps+1;

                if(isValid(u,v,m,n)) {
                    if(!grid[u][v] && h > dist[u][v]) {
                        dist[u][v] = h;
                        q.push({u,v,h,steps+1});
                    }
                    else if(grid[u][v] && h-1 >= 0 && h-1 > dist[u][v]) {
                        dist[u][v] = h-1;
                        q.push({u,v,h-1,steps+1});
                    }
                }
            }
        }

        return -1;
    }
};