class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0,ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0 && cnt!=0) {ans+=cnt*(cnt+1)/2;cnt=0;}
            else if(nums[i]==0) cnt++;
        }
        return ans+cnt*(cnt+1)/2;
    }
};