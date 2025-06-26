class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1,mid,index = - 1;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(nums[mid]==target) {
                index = mid;
                break;
            }
            if(nums[low]<=nums[mid]) {
                if(target>=nums[low] && target<=nums[mid]) high = mid;
                else low = mid+1;
            }
            else {
                if(target>=nums[mid] && target<=nums[high]) low = mid;
                else high = mid-1;
            }
        }
        return index;
    }
};