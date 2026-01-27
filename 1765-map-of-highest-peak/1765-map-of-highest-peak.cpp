class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> heights(m, vector<int>(n, -1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) {
                    q.push({i,j});
                    heights[i][j] = 0;
                }
            }
        }

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        int h = 0;
        while(!q.empty()) {
            int N = q.size();
            h++;
            while(N--) {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;

                for(int i=0; i<4; i++) {
                    int u = x + dx[i];
                    int v = y + dy[i];
                    if(isValid(u,v,m,n) && heights[u][v]==-1) {
                        q.push({u,v});
                        heights[u][v] = h;
                    }
                }
            }
        }
        return heights;
    }
};