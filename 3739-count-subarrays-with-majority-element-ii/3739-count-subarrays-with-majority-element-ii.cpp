class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int cs = 0;
        mpp[0] = 1;

        long long temp = 0;
        long long result = 0;

        for(int j=0; j<nums.size(); j++) {
            if(nums[j] == target) {
                temp+=mpp[cs];
                cs++;
            }
            else {
                cs--;
                temp-=mpp[cs];
            }
            mpp[cs]++;
            result+=temp;
        }
        return result;
    }
};