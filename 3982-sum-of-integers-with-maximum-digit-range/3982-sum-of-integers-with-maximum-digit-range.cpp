class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi = -1;
        for(int i=0; i<nums.size(); i++) {
            string s = to_string(nums[i]);
            sort(s.begin(),s.end());
            int m = s.size();
            mpp[s[m-1]-s[0]]+=nums[i];
            maxi = max(maxi,s[m-1]-s[0]);
        }

        for(auto it : mpp) {
            int x = it.first;
            int y = it.second;
            if(x==maxi) return y;
        }
        return 0;
    }
};