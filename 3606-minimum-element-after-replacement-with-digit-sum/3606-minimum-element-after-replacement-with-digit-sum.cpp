class Solution {
public:
    int digiSum(int x) {
        int sum = 0;
        while(x!=0) {
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            res = min(res,digiSum(nums[i]));
        }
        return res;
    }
};