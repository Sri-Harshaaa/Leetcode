class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=nums.size()-k; i++) {
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return k==1 ? 0 : ans;
    }
};