class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(),m = waterStartTime.size(),ans = INT_MAX,z;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int x = landStartTime[i]+landDuration[i];
                int y = waterStartTime[j]+waterDuration[j];
                if(waterStartTime[j]>x) x+=(waterStartTime[j]-x);
                x+=waterDuration[j];
                if(landStartTime[i]>y) y+=(landStartTime[i]-y);
                y+=landDuration[i];
                z = min(x,y);
                ans = min(ans,z);
            }
        }
        return ans;
    }
};