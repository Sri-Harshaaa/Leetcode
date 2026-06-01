class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        unordered_map<int,int> mpp;
        for(int i=0; i<s.size(); i++) {
            mpp[s[i]-'0']++;
        }
        int score = 0;
        for(auto it : mpp) {
            score+=(it.first*it.second);
        }
        return score;
    }
};