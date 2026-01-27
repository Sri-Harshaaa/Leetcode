class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int a = entrance[0];
        int b = entrance[1];

        queue<pair<pair<int,int>, int>> q;
        q.push({{a,b}, 0});
        maze[a][b] = '+';

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int steps = it.second;

            for(int i=0; i<4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(isValid(u,v,m,n) && maze[u][v]=='.') {
                    if(u==0 || u==m-1 || v==0 || v==n-1) return steps+1;

                    q.push({{u,v}, steps+1});
                    maze[u][v] = '+';
                }
            }
        }
        return -1;
    }
};