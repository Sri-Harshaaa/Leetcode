class Solution {
public:
    bool isValid(int n, int m, vector<vector<int>>& grid) {
        vector<bool> temp(10,false);
        for(int i=n; i<=n+2; i++) {
            for(int j=m; j<=m+2; j++) {
                int x = grid[i][j];
                if(x < 1 || x > 9) return false;
                else if(temp[x]) return false;
                else temp[x] = true;
            }
        }
        return true;
    }

    bool checkSum(int n, int m, vector<vector<int>>& grid) {
        int targetSum = grid[n][m]+grid[n][m+1]+grid[n][m+2];
        for(int i=0; i<3; i++) {
            int sum1 = 0,sum2 = 0;
            for(int j=0; j<3; j++) {
                sum1+=grid[n+i][m+j];
                sum2+=grid[n+j][m+i];
            }
            if(sum1!=targetSum || sum2!=targetSum) return false;
        }
        int diag1 = grid[n][m]+grid[n+1][m+1]+grid[n+2][m+2];
        int diag2 = grid[n][m+2]+grid[n+1][m+1]+grid[n+2][m];
        if(diag1!=targetSum || diag2!=targetSum) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),cnt = 0;
        for(int i=0; i<=n-3; i++) {
            for(int j=0; j<=m-3; j++) {
                if(grid[i+1][j+1]==5 && isValid(i,j,grid) && checkSum(i,j,grid)) cnt++;
            }
        }
        return cnt;
    }
};