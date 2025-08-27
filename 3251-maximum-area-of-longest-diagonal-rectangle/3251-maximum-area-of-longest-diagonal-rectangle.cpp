class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0,diag = INT_MIN;
        for(int i=0; i<dimensions.size(); i++) {
            int temp = dimensions[i][0]*dimensions[i][0]+ dimensions[i][1]*dimensions[i][1];\
            cout<<temp;
            if(temp > diag) {
                diag = temp;
                area = dimensions[i][0]*dimensions[i][1];
            }
            else if(temp==diag) area = max(area,dimensions[i][0]*dimensions[i][1]);
        }
        return area;
    }
};