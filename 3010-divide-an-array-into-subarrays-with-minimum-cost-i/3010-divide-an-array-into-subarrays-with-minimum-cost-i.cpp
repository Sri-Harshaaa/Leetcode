class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int cost = nums[0], mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i=1; i<n; i++) {
            if(nums[i] < mini1) {
                mini2 = mini1;
                mini1 = nums[i];
            }
            else if(nums[i] < mini2) mini2 = nums[i];
        }
        cost+=(mini1+mini2);
        return cost;
    }
};