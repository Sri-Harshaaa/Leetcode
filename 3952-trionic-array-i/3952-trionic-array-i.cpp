class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(),idx = n-3;
        if(n==3) return false;
        for(int i=0; i<n-3; i++) {
            if(nums[i]>=nums[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx==0) return false;
        int x = n-2;
        for(int i=idx; i<n-2; i++) {
            if(nums[i]<=nums[i+1]) {x = i;break;}
        }
        if(x==idx) return false;
        for(int i=x; i<n-1; i++) {
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
};