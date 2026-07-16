class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        int maxi = nums[0];
        pre[0] = nums[0];
        for(int i=1; i<n; i++) {
            maxi = max(maxi,nums[i]);
            pre[i] = __gcd(nums[i],maxi);
        }
        long long sum = 0;
        sort(pre.begin(), pre.end());
        for(int i=0; i<n/2; i++) {
            sum+=__gcd(pre[i],pre[n-1-i]);
        }
        return sum;
    }
};