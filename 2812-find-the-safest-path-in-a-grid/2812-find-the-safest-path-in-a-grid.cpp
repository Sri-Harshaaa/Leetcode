class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            int d = grid[x][y];

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,n,n) && !visited[u][v]) {
                    grid[u][v] = d+1;
                    visited[u][v] = true;
                    q.push({u,v});
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(n,INT_MIN));
        priority_queue<tuple<int,int,int>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int d = get<0>(t);
            int x = get<1>(t);
            int y = get<2>(t);

            if(d > dist[x][y]) continue;
            if(x == n-1 && y == n-1) return dist[x][y];

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,n,n) && dist[u][v] < min(d,grid[u][v])) {
                    dist[u][v] = min(d,grid[u][v]);
                    pq.push({dist[u][v],u,v});
                }
            }
        }

        return -1;
    }
};