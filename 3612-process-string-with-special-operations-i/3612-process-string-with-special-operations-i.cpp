class Solution {
public:
    string processStr(string s) {
        int n =s.size();
        string res;
        for(int i=0; i<n; i++) {
            if(isalpha(s[i])) res+=s[i];
            else if(res.size()!=0 && s[i]=='*') res.pop_back();
            else if(s[i]=='#') res+=res;
            else if(s[i]=='%') reverse(res.begin(),res.end());
        }
        return res;
    }
};