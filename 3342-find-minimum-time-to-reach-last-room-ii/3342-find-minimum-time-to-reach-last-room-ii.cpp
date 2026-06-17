class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> time(m, vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        time[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int t = p.first;
            int x = p.second.first;
            int y = p.second.second;
            int o = (x+y)%2 == 0 ? 1 : 2;

            if(x == m-1 && y == n-1) return time[x][y];
            if(t > time[x][y]) continue;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];

                if(isValid(u,v,m,n)) {
                    int wait = moveTime[u][v] <= t ? 0 : moveTime[u][v]-t;

                    if(t+wait+1 < time[u][v]) {
                        time[u][v] = t+wait+o;
                        pq.push({time[u][v],{u,v}});
                    }
                }
            }
        }

        return -1;
    }
};