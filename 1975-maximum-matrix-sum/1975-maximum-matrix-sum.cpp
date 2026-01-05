class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), neg = 0, mini = INT_MAX;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] < 0) neg++;
                if(abs(matrix[i][j]) < mini) mini = abs(matrix[i][j]);
                sum+=abs(matrix[i][j]);
            }
        }
        return neg%2 == 0 ? sum : sum-2*mini;
    }
};