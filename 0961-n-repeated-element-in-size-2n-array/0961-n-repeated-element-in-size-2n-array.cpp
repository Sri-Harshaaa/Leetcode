class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size()/2,ans = -1;
        for(int i=0; i<2*n; i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 2) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};