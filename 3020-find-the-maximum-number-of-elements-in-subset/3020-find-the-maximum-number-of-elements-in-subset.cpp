class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cnt_1 = 0;
        map<int,int> mpp;
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) cnt_1++;
            else mpp[nums[i]]++;
        }
        int ans = cnt_1%2 ? cnt_1 : cnt_1-1;
        for(auto& it : mpp) {
            long long a = it.first;
            if(st.count(a)) continue;
            long long x = a;
            while(mpp.count(x)) {
                st.insert(x);
                int y = log(x)/log(a);
                int len = 2*log2(y)+1;
                ans = max(ans,len);
                if(mpp[x] == 1 || x > LLONG_MAX/x) break;
                x*=x;
            }
        }

        return ans;
    }
};