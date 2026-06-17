class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        dq.push_front({0,0});

        while(!dq.empty()) {
            pair<int,int> p = dq.front();
            dq.pop_front();
            int x = p.first;
            int y = p.second;

            if(x == m-1 && y == n-1) return dist[m-1][n-1];

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                int dir = grid[x][y];

                if(isValid(u,v,m,n)) {
                    int w = (dir == i+1) ? 0 : 1; 

                    if(dist[x][y]+w >= dist[u][v]) continue;

                    dist[u][v] = dist[x][y]+w;

                    if(w==0) dq.push_front({u,v});
                    else dq.push_back({u,v});
                }
            }
        }

        return -1;
    }
};