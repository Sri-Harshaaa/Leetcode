class Solution {
public:
    
    void solve(int i,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans) {
        int n=nums.size();
        if(i==n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1,nums,curr,ans);
        curr.pop_back();
        int index=i+1;
        while(index<n && nums[index-1]==nums[index]) index++;
        solve(index,nums,curr,ans);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};