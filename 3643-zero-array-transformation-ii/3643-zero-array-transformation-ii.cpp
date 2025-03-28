class Solution {
public:
    bool solve(vector<int>& nums,int m,vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> arr(n+1);
        for(int i=0; i<m; i++) {
            arr[queries[i][0]]+=queries[i][2];
            arr[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1; i<n; i++) arr[i]+=arr[i-1];

        for(int i=0; i<n; i++) {
            if(nums[i]>arr[i]) return false;
            }
        return true;
     }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        bool isZero=true;
        for(auto &it: nums) {
            if(it!=0) isZero=false;
        }
        if(isZero) return 0;
        else {
            int l=1,r=m,mid,ans=-1;
            while(l<=r) {
                mid=(l+r)/2;
                if(solve(nums,mid,queries)) {ans=mid;r=mid-1;}
                else l=mid+1;
            }
            return ans;
        }
    }
};