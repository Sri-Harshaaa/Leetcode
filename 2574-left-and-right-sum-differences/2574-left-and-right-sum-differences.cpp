class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        leftsum.push_back(0);
        vector<int>rightsum;
        vector<int> ans;
        int pos = 0,sum1=0,sum2=0;
        for(int i=0; i<nums.size()-1; i++) {
            sum1=sum1+nums[i];
            leftsum.push_back(sum1);
        }
         for(int i=nums.size()-1; i>0; i--) {
            sum2=sum2+nums[i];
            rightsum.push_back(sum2);
        }
        for(int i=0; i<rightsum.size()/2; i++) {
            swap(rightsum[rightsum.size()-1-i],rightsum[i]);
        }
        rightsum.push_back(0);
        for(int i=0; i<nums.size(); i++) {
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return ans;
    }
};