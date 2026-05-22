class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1,mid;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            //this one works when low and high step into the sorted half
            if(nums[low]<=nums[high]) { //because if single element
                if(nums[mid]>target) high = mid-1;
                else low = mid+1;
            }
            //these work until the low and high step in the sorted half
            else if(nums[low]<=nums[mid]) {
                if(target>=nums[low] && target<nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else {
                if(target>nums[mid] && target<=nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};

//notice the <=  >= and < >