class Solution {
public:
    int solve_c2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp2) {
        int n = fruits.size();
        if (i == n-1 && j == n-1) return 0;
        if (i > j || i >= n || j >= n || i == j) return -1;

        if (dp2[i][j] != -2) return dp2[i][j];

        int down = solve_c2(i+1, j, fruits, dp2);
        int leftDiag = solve_c2(i+1, j-1, fruits, dp2);
        int rightDiag = solve_c2(i+1, j+1, fruits, dp2);

        int best = max({down, leftDiag, rightDiag});
        dp2[i][j] = (best == -1 ? -1 : fruits[i][j] + best);
        return dp2[i][j];
    }

    int solve_c3(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp3) {
        int n = fruits.size();
        if (i == n-1 && j == n-1) return 0;
        if (j > i || i >= n || j >= n || i == j || i < 0) return -1;

        if (dp3[i][j] != -2) return dp3[i][j];

        int right = solve_c3(i, j+1, fruits, dp3);
        int topDiag = solve_c3(i-1, j+1, fruits, dp3);
        int downDiag = solve_c3(i+1, j+1, fruits, dp3);

        int best = max({right, topDiag, downDiag});
        dp3[i][j] = (best == -1 ? -1 : fruits[i][j] + best);
        return dp3[i][j];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int c1 = 0;
        for (int i = 0; i < n; i++) c1 += fruits[i][i];

        vector<vector<int>> dp2(n, vector<int>(n, -2));
        vector<vector<int>> dp3(n, vector<int>(n, -2));

        int c2 = solve_c2(0, n-1, fruits, dp2);
        int c3 = solve_c3(n-1, 0, fruits, dp3);

        return c1 + (c2 == -1 ? 0 : c2) + (c3 == -1 ? 0 : c3);
    }
};
