class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(),m = mat[0].size(),x=0;
        for(int i=0; i<=(n-1)+(m-1); i++) {
            x++;
            if(x%2==0) {
                for(int j=0; j<n; j++) {
                int k = abs(i-j);
                if(k+j==i && k<m) ans.push_back(mat[j][k]);
                }
            }
            else {
                for(int j=n-1; j>=0; j--) {
                int k = abs(i-j);
                if(j+k==i && k<m) ans.push_back(mat[j][k]);
                }
            }
        }
        return ans;
    }
};