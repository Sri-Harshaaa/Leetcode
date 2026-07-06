class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b) {
            return abs(a[0]-a[1]) > abs(b[0]-b[1]);
        });

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            for(int j=i+1; j<n; j++) {
                int u = intervals[j][0];
                int v = intervals[j][1];
                if(x<=u && v<=y && !visited[j]) {
                    visited[j] = true;
                    cnt++;
                }
            }
        }

        return n-cnt;
    }
};