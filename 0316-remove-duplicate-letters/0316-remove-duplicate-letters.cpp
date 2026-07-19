class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans;
        vector<int> last(26,0);
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++) last[s[i]-'a'] = i;

        ans+=s[0];
        visited[s[0]-'a'] = true;
        for(int i=1; i<n; i++) {
            int ch = s[i]-'a';
            if(visited[ch]) continue;

            visited[ch] = true;

            if(ans.back() < s[i]) {
                ans+=s[i];
                continue;
            }

            while(!ans.empty() && ans.back() > s[i] && last[ans.back()-'a'] > i) {
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans+=s[i];
        }

        return ans;
    }
};