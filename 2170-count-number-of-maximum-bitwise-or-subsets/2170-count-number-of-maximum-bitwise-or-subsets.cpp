class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& temp,map<int,int>& mpp) {
        int n = nums.size();
        if(i==n) {
            int ans = 0;
            for(int i=0; i<temp.size(); i++) ans|=temp[i];
            mpp[ans]++;
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,mpp);

        temp.pop_back();
        solve(i+1,nums,temp,mpp);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        map<int,int> mpp;
        solve(0,nums,temp,mpp);
        return mpp.rbegin()->second;
    }
};