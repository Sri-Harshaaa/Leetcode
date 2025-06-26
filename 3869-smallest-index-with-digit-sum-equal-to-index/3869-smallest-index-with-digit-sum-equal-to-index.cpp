class Solution {
public:
    int digiSum(int x) {
        int sum = 0;
        while(x!=0) {
            int digit = x%10;
            sum+=digit;
            x=x/10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(digiSum(nums[i])==i) return i;
        }
        return -1;
    }
};