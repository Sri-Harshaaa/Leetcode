class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        unordered_map<int,int> mpp;
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int rank = 1;
        for(int i=0; i<n; i++) {
            if(mpp.count(temp[i])) continue;
            mpp[temp[i]] = mpp.size()+1;
        }
        for(int i=0; i<n; i++) {
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};