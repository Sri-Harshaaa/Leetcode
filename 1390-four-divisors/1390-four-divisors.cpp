class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int sum = 0, m = sqrt(nums[i]), cnt = 0;
            cout <<m;
            for(int j=1; j<=m; j++) {
                if(nums[i]%j == 0) {
                    if(j*j == nums[i]) {
                        sum+=j;
                        cnt++;
                    }
                    else {
                        sum+=(j + (nums[i]/j) );
                        cnt+=2;
                    }
                }
            }
            if(cnt == 4) ans+=sum;
        }
        return ans;
    }
};