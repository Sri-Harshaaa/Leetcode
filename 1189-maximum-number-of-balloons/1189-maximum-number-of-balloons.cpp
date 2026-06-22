class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(5,0);
        for(int i=0; i<text.size(); i++) {
            char ch = text[i];
            if(ch == 'b') freq[0]++;
            else if(ch == 'a') freq[1]++;
            else if(ch == 'l') freq[2]++;
            else if(ch == 'o') freq[3]++;
            else if(ch == 'n') freq[4]++;
        }

        int m1 = min({freq[0],freq[1],freq[4]});
        int m2 = min(freq[2],freq[3]);

        return min(m1,m2/2);
    }
};