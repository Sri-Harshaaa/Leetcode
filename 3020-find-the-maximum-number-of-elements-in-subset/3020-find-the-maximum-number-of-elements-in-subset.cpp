class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cnt_1 = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) cnt_1++;
            else mpp[nums[i]]++;
        }
        int ans = cnt_1%2 ? cnt_1 : cnt_1-1;
        for(auto& it : mpp) {
            long long a = it.first;
            long long x = a;
            int cnt = -1;
            while(mpp.count(x)) {
                cnt++;
                ans = max(ans,2*cnt+1);
                if(mpp[x] == 1 || x > LLONG_MAX/x) break;
                x*=x;
            }
        }

        return ans;
    }
};