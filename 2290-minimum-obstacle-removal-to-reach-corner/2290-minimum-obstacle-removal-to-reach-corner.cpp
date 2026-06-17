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
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = grid[0][0] == 0 ? 0 : 1;
        pq.push({dist[0][0],{0,0}});

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if(x == m-1 && y == n-1) return dist[x][y];
            if(d > dist[x][y]) continue;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,m,n)) {
                    int w = grid[u][v];
                    if(d+w < dist[u][v]) {
                        dist[u][v] = d+w;
                        pq.push({d+w,{u,v}});
                    }
                } 
            }
        }

        return -1;
    }
};