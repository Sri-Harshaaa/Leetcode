class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            ans = min(ans, nums[mid]);

            if (nums[mid] > nums[high]) {
                // Minimum must be on the right
                low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                // Minimum must be on the left (including mid)
                high = mid - 1;
            }
            else {
                // nums[mid] == nums[high] → cannot determine → shrink high safely
                high--;
            }
        }

        return ans;
    }
};
