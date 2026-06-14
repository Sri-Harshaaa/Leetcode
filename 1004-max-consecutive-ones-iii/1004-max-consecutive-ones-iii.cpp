class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),i=0,j=0;
        int ans = 0, count = 0;
        while(j < n) {
            if(!nums[j]) count++;

            if(count <= k) ans = max(ans,j-i+1);
            else {
                if(!nums[i]) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};