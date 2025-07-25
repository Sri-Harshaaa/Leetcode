class Solution {
public:
    string makeFancyString(string s) {
        string ans = s.substr(0,2);
        for(int i=2; i<s.size(); i++) {
            if(s[i]!=ans[ans.size()-1] || s[i]!=ans[ans.size()-2]) ans+=s[i];
        }
        return ans;
    }
};