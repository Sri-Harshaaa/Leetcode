class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mn=nums[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=nums[i]-mn;
        }
        return ans;
    }
};