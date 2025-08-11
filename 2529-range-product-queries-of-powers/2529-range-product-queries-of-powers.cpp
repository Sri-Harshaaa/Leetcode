class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers,ans;
        int sum = 0;
        const int MOD = 1000000007;
        for(int i=29; i>=0; i--) {
            int x = 1<<i;
            if(sum+x>n) continue;
            sum+=x;
            powers.push_back(x);
            if(sum==n) break;
        }
        sort(powers.begin(),powers.end());
        for(int i=0; i<queries.size(); i++) {
            int product = 1;
            for(int j=queries[i][0]; j<=queries[i][1]; j++) {
                product = (1LL*(product % MOD)*(powers[j] % MOD)) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
    }
};