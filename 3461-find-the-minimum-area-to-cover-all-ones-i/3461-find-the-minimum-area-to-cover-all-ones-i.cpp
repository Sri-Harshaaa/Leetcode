class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int w1=INT_MAX,w2=INT_MIN,l1=INT_MAX,l2=INT_MIN;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1) {
                    w1 = min(w1,j);
                    w2 = max(w2,j);
                    l1 = min(l1,i);
                    l2 = max(l2,i);
                }
            }
        }
        return (l2-l1+1)*(w2-w1+1);
    }
};