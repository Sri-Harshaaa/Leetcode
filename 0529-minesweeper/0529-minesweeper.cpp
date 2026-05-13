class Solution {
public:
    vector<int> dx = {0,0,-1,1,-1,1,-1,1};
    vector<int> dy = {1,-1,0,0,1,1,-1,-1};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    void solve(int a, int b, vector<vector<int>>& temp, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        board[a][b] = 'B';

        for(int i=0; i<8; i++) {
            int u = a + dx[i];
            int v = b + dy[i];
            if(isValid(u,v,m,n) && board[u][v] == 'E') {
                if(temp[u][v]) board[u][v] = temp[u][v] + '0';
                else {
                    solve(u,v,temp,board);
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp(m, vector<int>(n,0));

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'M') q.push({i,j});
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<8; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(isValid(X,Y,m,n)) {
                    temp[X][Y]++;
                } 
            }
        }

        int a = click[0];
        int b = click[1];

        if(board[a][b] == 'M') {
            board[a][b] = 'X';
            return board;
        }
        else if(temp[a][b]) {
            board[a][b] = temp[a][b] + '0';
            return board;
        }
        else {
            solve(a,b,temp,board);
            return board;
        }
    }
};