class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) {
                    q.push({{i,j}, 0});
                    isWater[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }


        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int h = it.second;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(isValid(u,v,m,n) && !visited[u][v] && isWater[u][v]==0) {
                    visited[u][v] = true;
                    q.push({{u,v}, h+1});
                    isWater[u][v] = h+1;
                }
            }
        }
        return isWater;
    }
};