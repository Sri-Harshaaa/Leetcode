class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--) {
            int a = nums[i];
            while(a != 0) {
                int temp = a%10;
                a = a/10;
                ans.push_back(temp);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};