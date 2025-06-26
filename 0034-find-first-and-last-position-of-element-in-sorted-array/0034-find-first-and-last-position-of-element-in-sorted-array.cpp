class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int l=0,h=n-1,mid,index1=-1,index2=-1;
        while(l<=h) {
            mid = l + (h-l)/2;
            if(nums[mid]>=target) {
                index1 = mid;
                h = mid -1;
            }
            else l = mid+1;
        }
        l =0,h =n-1;;
        while(l<=h) {
            mid = l + (h-l)/2;
            if(nums[mid]>target) {
                index2 = mid;
                h = mid -1;
            }
            else l = mid+1;
        }
        if(index1==-1|| nums[index1]!=target ) ans = {-1,-1};
        else {
            if(index2==-1) ans = {index1,n-1};
            else ans = {index1,index2-1};
        }
        return ans;
    }
};