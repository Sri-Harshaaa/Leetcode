class Solution {
public:
    bool isValid(vector<int>& nums, int k) {
        long long limit = 1LL*k*k, op = 0;
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i]/k;
            if(nums[i]%k == 0) op+=a;
            else op+=(a+1);
        }
        return op<=limit ? true : false;
    }

    int minimumK(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int low = 1, high = 1e5;
        while(low <= high) {
            int k = (low+high)/2;
            if(isValid(nums,k)) {
                ans = k;
                high = k-1;
            }
            else low = k+1;
        }
        return ans;
    }
};