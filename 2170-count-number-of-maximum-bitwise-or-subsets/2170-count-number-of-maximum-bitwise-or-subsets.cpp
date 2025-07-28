class Solution {
public:
    int ans = 0,max_or = 0;

    void solve(int i,int temp,vector<int>& nums) {
        if(i==nums.size()) {
            if(temp==max_or) ans++;
            return;
        }
        
        solve(i+1,temp | nums[i],nums);

        solve(i+1,temp,nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(),temp = 0;
        for(int i=0; i<n; i++) max_or|=nums[i];
        solve(0,temp,nums);
        return ans;
    }
};