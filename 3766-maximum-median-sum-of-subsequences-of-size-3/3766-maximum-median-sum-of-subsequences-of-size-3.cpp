class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size(),i=1;
        long long ans = 0;
        sort(nums.begin(),nums.end());
        int temp = n/3;
        while(temp--) {
            ans+=nums[n-i-1];
            i+=2;
        }
        return ans;
    }
};