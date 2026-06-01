class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0, n = cost.size();
        sort(cost.begin(), cost.end());
        for(int i=n-1; i>=0; i-=3) {
           if(i == 0) ans+=cost[i];
           else ans+=(cost[i]+cost[i-1]);
        }
        return ans;
    }
};