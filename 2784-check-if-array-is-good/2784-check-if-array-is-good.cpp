class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        sort(nums.begin(), nums.end());
        if(n != nums[n-1]+1) return false;
        for(int i=0; i<n-2; i++) {
            if(nums[i+1] - nums[i] != 1) return false;
        }
        if(nums[n-1] != nums[n-2]) return false;
        return true;
    }
};