class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int a = n/8;
        int b = 8*(a*(a+1)/2);
        int c = n%8;
        int d = c*(a+1);
        return b+d;
    }
};