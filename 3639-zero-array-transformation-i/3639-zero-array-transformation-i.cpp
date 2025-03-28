class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> arr(n+1);
        for(int i=0; i<queries.size(); i++) {
            arr[queries[i][0]]++;
            arr[queries[i][1]+1]--;
        }
        for(int i=1; i<n; i++) {
            arr[i]+=arr[i-1];   
        }
        for(int i=0; i<n; i++) {
            if(nums[i]>arr[i]) return false;
        }
        return true;
    }
};