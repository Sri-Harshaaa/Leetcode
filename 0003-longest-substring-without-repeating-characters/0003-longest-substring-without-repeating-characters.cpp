class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int> mpp;
        int ans=0,temp=0;
        while(r<n) {
            if(mpp.find(s[r])==mpp.end()) {
                mpp[s[r]]=r;
                r++;
                ans=max(ans,r-l);
            }
            else {
                ans= max(ans,r-l);
                int x = mpp[s[r]]+1;
                while(l!=x) {
                    mpp.erase(s[l]);
                    l++;
                }
            }
        }
        return ans;
    }
};