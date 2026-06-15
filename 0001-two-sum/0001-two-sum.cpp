class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) {
            if(mpp.count(target-nums[i])) return {i,mpp[target-nums[i]]};
            mpp[nums[i]] = i;
        }
        return {};
    }
};