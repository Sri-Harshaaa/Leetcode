class Solution {
public:
    void generate(int n,string s,vector<string>& ans) {
        if(s.size()==2*n) {
            stack<char> st;
            for(int i=0; i<2*n; i++) {
                if(s[i]=='(') st.push('(');
                else {
                    if(!st.empty() && st.top()=='(') st.pop();
                    else st.push(')');
                }
            }
            if(st.empty()) ans.push_back(s);
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