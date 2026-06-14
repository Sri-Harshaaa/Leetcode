class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        vector<int> mpp(256,-1);
        while(j<n) {
            if(mpp[s[j]] == -1) {
                ans = max(ans,j-i+1);
                mpp[s[j]] = j;
                j++;
            }
            else {
                int m = mpp[s[j]];
                while(i<=m) {
                    mpp[s[i]] = -1;
                    i++;
                }
            }
        }
        return ans;
    }
};