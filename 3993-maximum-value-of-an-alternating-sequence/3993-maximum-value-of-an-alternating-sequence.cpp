class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return max(s+(1LL*(n/2)*m)-((n-1)/2), s+((1LL*(n-1)/2)*m)-(n-2)/2);
    }
};