class Solution {
public:
    void generate(int n,string s,vector<string>& ans) {
        if(s.size()==2*n) {
            int cnt=0;
            for(int i=0; i<2*n; i++) {
                if(s[i]=='(') cnt++;
                else cnt--;
                if(cnt<0) return;
            }
            if(cnt==0) ans.push_back(s);
            return;
        }

        s+='(';
        generate(n,s,ans);
        s.pop_back();
        s+=')';
        generate(n,s,ans);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;
        generate(n,temp,ans);
        return ans;
    }
};