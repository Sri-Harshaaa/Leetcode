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
                temp++;
                r++;
            }
            else {
                ans= max(ans,temp);
                int x = mpp[s[r]]+1;
                temp-=(x-l);
                while(l!=x) {
                    mpp.erase(s[l]);
                    l++;
                }
            }
        }
        return max(ans,temp);
    }
};