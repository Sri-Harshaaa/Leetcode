class Solution {
public:
    bool isValid(int x, int y , int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        dist[0][0] = grid[0][0] == 0 ? 0 : 1;
        visited[0][0] = false;
        dq.push_front({0,0});

        while(!dq.empty()) {
            pair<int,int> p = dq.front();
            dq.pop_front();
            int x = p.first;
            int y = p.second;
            if(x == m-1 && y == n-1) return dist[x][y];

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,m,n) && !visited[u][v]) {
                    int w = grid[u][v];
                    if(w==0) {
                        dist[u][v] = dist[x][y];
                        dq.push_front({u,v});
                    }
                    else {
                        dist[u][v] = dist[x][y]+1;
                        dq.push_back({u,v});
                    }
                    visited[u][v] = true;
                } 
            }
        }

        return -1;
    }
};