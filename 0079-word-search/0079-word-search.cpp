class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    bool solve(int x, int y, int i, string& word, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        char ch = board[x][y];

        if(board[x][y] == word[i]) board[x][y] = '.';
        else return false;
        if(i == word.size()-1) return true;

        for(int j=0; j<4; j++) {
            int u = x + dx[j];
            int v = y + dy[j];

            if(isValid(u,v,m,n)) {
                if(solve(u,v,i+1,word,board)) return true;
            }
        }

        board[x][y] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && solve(i,j,0,word,board)) return true; 
            }
        }
        return false;
    }
};