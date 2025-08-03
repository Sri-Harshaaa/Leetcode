class Solution {
public:
    long long upperBound(vector<int> &nums, long long x){
        int n = nums.size(),index = -1;
        int l = 0,h = n-1,mid;
        while(l<=h) {
            mid = l +(h-l)/2;
            if(nums[mid]>x) {
                index = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return index;
    }

    int minRemoval(vector<int>& nums, int k) {
        long long n = nums.size(),ans = INT_MAX,i;
        sort(nums.begin(),nums.end());
        for(i=0; i<n; i++) {
            long long idx = upperBound(nums,1LL*nums[i]*k);
            cout<<idx<<" ";
            if(idx==-1) ans = min(ans,i);
            else ans = min(ans,i+n-idx);
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};