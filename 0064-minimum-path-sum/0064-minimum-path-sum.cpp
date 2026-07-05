class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {1,0};
        vector<int> dy = {0,1};
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({dist[0][0],0,0});

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int d = get<0>(t);
            int x = get<1>(t);
            int y = get<2>(t);

            if(d > dist[x][y]) continue;
            if(x == m-1 && y == n-1) return dist[m-1][n-1];

            for(int i=0; i<2; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,m,n) && (d+grid[u][v] < dist[u][v])) {
                    dist[u][v] = d+grid[u][v];
                    pq.push({dist[u][v],u,v});
                } 
            }
        }

        return -1;
    }
};