class Solution {
public:
    void generate(int n,int cnt1,int cnt2,string s,vector<string>& ans) {
        if(s.size()==2*n) {
            ans.push_back(s);
            return;
        }

        cnt1++;
        if(cnt1<=n) {
            s+='(';
            generate(n,cnt1,cnt2,s,ans);
            s.pop_back();
        }
        cnt1--;
        cnt2++;
        if(cnt2<=cnt1) {
            s+=')';
            generate(n,cnt1,cnt2,s,ans);
            s.pop_back();
        }
         cnt2--;
    }

    vector<string> generateParenthesis(int n) {
        string temp="";
        int cnt1 = 0,cnt2 = 0;
        vector<string> ans;
        generate(n,cnt1,cnt2,temp,ans);
        return ans;
    }
};