class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if(d > dist[x][y]) continue;
            
            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,m,n)) {
                    int w = abs(heights[x][y]-heights[u][v]);
                    if(max(d,w) < dist[u][v]) {
                        dist[u][v] = max(d,w);
                        pq.push({max(d,w),{u,v}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};