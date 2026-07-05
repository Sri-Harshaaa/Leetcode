class Solution {
public:
    const int MOD = 1e9+7;

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[0][0] = '0';
        vector<int> dx = {1,0,1};
        vector<int> dy = {0,1,1};
        vector<vector<int>> dist(n, vector<int>(n,INT_MIN));
        vector<vector<int>> ways(n, vector<int>(n,0));
        dist[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;
        
        for(int x=n-1; x>=0; x--) {
            for(int y=n-1; y>=0; y--) {
                if(x == n-1 && y == n-1 || board[x][y] == 'X') continue;

                for(int i=0; i<3; i++) {
                    int u = x + dx[i];
                    int v = y + dy[i];

                    if(isValid(u,v,n,n) && board[u][v] != 'X' && dist[u][v]!=INT_MIN) {
                        int w = board[x][y]-'0';

                        if((dist[u][v]+w)%MOD > dist[x][y]) {
                            dist[x][y] = (dist[u][v]+w)%MOD;
                            ways[x][y] = ways[u][v];
                        }
                        else if((dist[u][v]+w)%MOD == dist[x][y]) ways[x][y] = (ways[u][v]+ways[x][y])%MOD;
                    }
                }
            }
        }
        if(dist[0][0]==INT_MIN) return {0,0};
        return {dist[0][0],ways[0][0]};
    }
};