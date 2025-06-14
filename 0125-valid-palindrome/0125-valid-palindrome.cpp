class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            char ch = tolower(s[i]);
        if((ch>='a' && ch<='z') || ch>='0' && ch<='9') ans+=ch;
        }
        int l=0,r=ans.size()-1;
        while(l<=r) {
            if(ans[l]!=ans[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};