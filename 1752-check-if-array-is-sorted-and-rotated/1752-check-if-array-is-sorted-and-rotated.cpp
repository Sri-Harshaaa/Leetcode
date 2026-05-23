class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return true;
        int count = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                for(int j=0; j<i; j++) {
                    if(nums[j] < nums[n-1]) return false;
                }
                count++;
            }
        }
        return count <= 1;
    }
};