class Solution {
public:
    const int MOD = 1e9+7;
    vector<long long> pre;
    vector<long long> nums;
    vector<int> nz_cnt;

    long long power(long long a, long long b) {
        long long res = 1;
        a%=MOD;
        while(b > 0) {
            if(b&1) res = (res*a)%MOD;
            a = (a*a)%MOD;
            b>>=1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = s.size();
        pre.resize(n,0);
        nums.resize(n,0);
        nz_cnt.resize(n,0);
        pre[0] = s[0]-'0';
        for(int i=1; i<n; i++) {
            pre[i] = (pre[i-1]+(s[i]-'0'))%MOD;
        }
        int j = 0;
        while(j<n && s[j] == '0') j++;
        if(j<n) nums[j] = s[j]-'0';
        j++;
        for(int i=j; i<n; i++) {
            int digit = s[i]-'0';
            nums[i] = s[i]=='0' ? nums[i-1] : ((nums[i-1]*10)%MOD + digit)%MOD;
        }
        nz_cnt[0] = s[0]=='0' ? 0 : 1;
        for(int i=1; i<n; i++) {
            nz_cnt[i] = s[i]=='0' ? nz_cnt[i-1] : nz_cnt[i-1]+1; 
        }
        vector<int> ans(q);
        for(int i=0; i<q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = l!=0 ? nz_cnt[r]-nz_cnt[l-1] : 0;
            long long num = l!=0 ? (nums[r] - (nums[l-1]*power(10,k))%MOD + MOD)%MOD : nums[r]%MOD;
            long long sum = l!=0 ? (pre[r]-pre[l-1]%MOD + MOD)%MOD : pre[r]%MOD;
            int sol = (num*sum)%MOD;
            ans[i] = sol;
        }
        return ans;
    }
};