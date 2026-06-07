class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int n = s.size();
        for(int i=1; i<n; i++) {
            if(s[i]=='0') continue;

            int mini = INT_MAX, index = -1, k = i-1;
            while(s[i] == '1') {
                if(nums[i] < mini) {
                    mini = nums[i];
                    index = i;
                }
                i++;
            }

            if(s[k] != '0') continue;

            if(nums[k] > nums[index]) swap(s[k],s[index]);
        } 

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') ans+=nums[i];
        }

        return ans;
    }
};