class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans,powers;
        for(int i=0; i<=29; i++) {
            if((n & 1<<i) != 0) powers.push_back(1<<i);
        }
        const int MOD = 1000000007;
        sort(powers.begin(),powers.end());
        for(int i=0; i<queries.size(); i++) {
            long long product = 1;
            for(int j=queries[i][0]; j<=queries[i][1]; j++) {
                product = (product*powers[j]) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
    }
};