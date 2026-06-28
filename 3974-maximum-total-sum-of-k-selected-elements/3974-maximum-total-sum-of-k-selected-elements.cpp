class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=n-1; i>=n-k; i--) {
            if(mul<=0) ans+=nums[i];
            else {
                ans+=(1LL*mul*nums[i]);
                mul--;
            }
        }
        return ans;
    }
};