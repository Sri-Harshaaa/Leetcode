class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int target = nums[(n-1)/2];
        for(int i=0; i<n/2; i++) {
            if(nums[i]==target || nums[i+(n/2)+1]==target) return false;
        }
        return true;
    }
};