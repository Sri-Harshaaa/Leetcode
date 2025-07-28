class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(),cnt = 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i]!=temp[temp.size()-1]) temp.push_back(nums[i]);
        }
        for(int i=1; i<temp.size()-1; i++) {
            if( (temp[i-1]>temp[i]&&temp[i]<temp[i+1]) || (temp[i-1]<temp[i]&&temp[i]>temp[i+1]) ) cnt++;
        }
        return cnt;
    }
};