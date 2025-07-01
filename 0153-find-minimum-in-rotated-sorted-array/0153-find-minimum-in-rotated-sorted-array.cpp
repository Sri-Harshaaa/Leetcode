class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mid,ans=INT_MAX;
        while(low<=high) {
            mid=(low+high)/2;
            // if(nums[low]<nums[high]) {
            //     ans=min(ans,nums[low]);
            //     break;
            // }
            if(nums[mid]<=nums[high]) {
                ans = min(nums[mid],ans);
                high = mid-1;
            }
            else low = mid +1;
        }
        return ans;
    }
}; 