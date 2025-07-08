class Solution {
public:
    bool isVowel(char ch) {
        char c = tolower(ch);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i<j) {
            if(isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!isVowel(s[i])) i++;
            if(!isVowel(s[j])) j--;
        }
        return s;
    }
};