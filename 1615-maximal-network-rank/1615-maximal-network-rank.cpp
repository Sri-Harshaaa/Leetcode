class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int cnt = 0;
                for(int k=0; k<roads.size(); k++) {
                    if(roads[k][0] == i || roads[k][1] == i) cnt++;
                    else if(roads[k][0] == j || roads[k][1] == j) cnt++;
                }
                ans = max(ans,cnt);
            }
        }

        return ans;
    }
};