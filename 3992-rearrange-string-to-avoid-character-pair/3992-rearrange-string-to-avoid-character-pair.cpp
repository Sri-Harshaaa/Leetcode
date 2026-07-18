class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int j = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==y) {
                swap(s[j],s[i]);
                j++;
            }
        }
        return s;
    }
};