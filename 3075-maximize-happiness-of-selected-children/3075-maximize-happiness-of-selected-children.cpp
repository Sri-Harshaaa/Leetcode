class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long ans = 0;
        int i = n-1, j = 0;
        sort(happiness.begin(),happiness.end());
        while(k--) {
            if(happiness[i]-j > 0)ans += happiness[i] - j;
            else break;
            j++;
            i--;
        }
        return ans;
    }
};