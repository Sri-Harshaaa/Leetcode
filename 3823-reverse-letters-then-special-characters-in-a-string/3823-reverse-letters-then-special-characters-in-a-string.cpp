class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        vector<char> letters, ch;
        for(int i=0; i<n; i++) {
            int a = s[i]-'a';
            if(a>=0 && a<26) letters.push_back(s[i]);
            else ch.push_back(s[i]);
        }
        reverse(letters.begin(), letters.end());
        reverse(ch.begin(), ch.end());
        int j = 0, k = 0;
        for(int i=0; i<n; i++) {
            int a = s[i]-'a';
            if(a>=0 && a<26) {
                s[i] = letters[j];
                j++;
            }
            else {
                s[i] = ch[k];
                k++;
            }
        }
        return s;
    }
};