class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(),m = waterStartTime.size(),ans = INT_MAX,z;
        int a, b, x, y;
        a = b = x = y = INT_MAX;
        for(int i=0; i<n; i++) x = min(x,landStartTime[i]+landDuration[i]);
        for(int i=0; i<m; i++) y = min(y,waterStartTime[i]+waterDuration[i]); 
        for(int i=0; i<n; i++) {
            if(landStartTime[i]>y) a = min(a,(landStartTime[i]-y)+landDuration[i]);
            else a = min(a,landDuration[i]);
        }
        for(int i=0; i<m; i++) {
            if(waterStartTime[i]>x) b = min(b,(waterStartTime[i]-x)+waterDuration[i]);
            else b = min(b,waterDuration[i]);
        }
        return min(x+b,y+a);
    }
};