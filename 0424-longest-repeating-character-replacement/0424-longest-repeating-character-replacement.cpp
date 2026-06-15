class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26,0);
        int n = s.size(), ans = 0, mxf = 0;
        int i = 0, j = 0;
        while(j<n) {
            mpp[s[j]-'A']++;
            mxf = max(mxf,mpp[s[j]-'A']);
            if(j-i+1-mxf <= k) ans = max(ans,j-i+1);
            else {
                mpp[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};