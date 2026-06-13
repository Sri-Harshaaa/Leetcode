class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s;
        for(int i=0; i<words.size(); i++) {
            int wt = 0;
            for(int j=0; j<words[i].size(); j++) {
                wt+=weights[words[i][j]-'a'];
            }
            wt%=26;
            s+=('z'-wt);
        }
        return s;
    }
};