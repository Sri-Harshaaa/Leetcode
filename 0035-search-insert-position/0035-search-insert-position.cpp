class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(),index = n;
        int low = 0,high = n-1,mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(nums[mid]>=target) {
                index = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return index;
    }
};