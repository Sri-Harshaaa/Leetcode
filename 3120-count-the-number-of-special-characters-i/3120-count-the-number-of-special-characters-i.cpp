class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26,0),big(26,0);
        int count = 0;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                int k = word[i]-'a';
                int l = toupper(word[i])-'A';
                if(big[l] && !small[k]) {
                    count++;
                }
                small[k] = 1;
            }
            else {
                int k = tolower(word[i])-'a';
                int l = word[i]-'A';
                if(small[k] && !big[l]) {
                    count++;
                }
                big[l] = 1;
            }
        }
        return count;
    }
};