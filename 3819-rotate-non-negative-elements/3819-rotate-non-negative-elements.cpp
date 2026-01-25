class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++) if(nums[i]>=0) arr.push_back(nums[i]);
        int m = arr.size();
        if(m!=0) k%=m;
        vector<int> temp(m);
        for(int i=0; i<m; i++) {
            int j = (m+i-k)%m;
            temp[j] = arr[i];
        }
        int j = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]>=0) {
                nums[i] = temp[j];
                j++;
            }
        }
        return nums;
    }
};