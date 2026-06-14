class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char,int> mpp;
        while(j<n) {
            if(!mpp.count(s[j])) {
                ans = max(ans,j-i+1);
                mpp[s[j]] = j;
                j++;
            }
            else {
                int m = mpp[s[j]];
                while(i<=m) {
                    mpp.erase(s[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};