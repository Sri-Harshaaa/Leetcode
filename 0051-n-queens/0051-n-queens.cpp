class Solution {
public:
    void solve(int i,int n,vector<vector<int>>& pos,vector<string>& board,           vector<vector<string>>& ans) {
        if(i==n) {
            ans.push_back(board);
            return;
        };

        for(int j=0; j<n; j++) {
            if(pos[0][j]==1 || pos[1][i+j]==1 || pos[2][i-j+n-1]==1) continue;
            board[i][j] = 'Q';
            pos[0][j] = 1;
            pos[1][i+j] = 1;
            pos[2][i-j+n-1] = 1;
            solve(i+1,n,pos,board,ans);
            board[i][j] = '.';
            pos[0][j] = 0;
            pos[1][i+j] = 0;
            pos[2][i-j+n-1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return {{"Q"}};
        else if(n==2) return {};
        else {
            vector<vector<string>> ans;
            vector<string> board(n,string(n,'.'));
            vector<int> col(n,0),d1(2*n-1,0),d2(2*n-1,0);
            vector<vector<int>> pos;
            pos.push_back(col);
            pos.push_back(d1);
            pos.push_back(d2);
            solve(0,n,pos,board,ans);
            return ans;
        }
    }
};