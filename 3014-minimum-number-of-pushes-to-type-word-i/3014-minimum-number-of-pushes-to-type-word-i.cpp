class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        return 8*((n/8)*((n/8)+1)/2)+(n%8)*((n/8)+1);
    }
};