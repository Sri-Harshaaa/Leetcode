class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(),temp = nums[0] ,ans=1,o = 0, e = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]%2==0) e++;
            else o++;
            if((nums[i]+temp)%2==1) {
                temp = nums[i];
                ans++;
            }
        }
        return max(ans,max(o,e));
    }
};