class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int n = fruits.size(),ans = 0,i=0,j=0;
        while(j<n) {
            mpp[fruits[j]] = j;
            if(mpp.size()==3) {
                mpp[fruits[j]]=j;
                int minKey = -1, minVal = INT_MAX;
                 for (auto& [key, val] : mpp) {
                     if (val < minVal) {
                         minVal = val;
                         minKey = key;
                     }
                 }
                 mpp.erase(minKey);
                 i = minVal+1;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};