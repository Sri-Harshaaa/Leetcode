class Solution {
public:
    bool isvowel(char ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        else return false;
    }

    bool isValid(string word) {
        int cost = 0,vow=0,num=0,cr=0;
        for(int i=0; i<word.size(); i++) {
            char ch = tolower(word[i]);
            if(isalpha(ch)) {
                cr++;
                if(isvowel(ch)) vow++;
                else cost++;
            }
            else if(isdigit(ch)) num++;
            else return false;
        }
        if(cost==0 || vow==0 || word.size()<3) return false;
        else return true;
    }
};