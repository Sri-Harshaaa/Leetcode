class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int a = numBottles,empty=0;
        while(a!=0) {
            ans+=a;
            int y = a+empty;
            a = (y/numExchange);
            empty = y%numExchange;
        }
        return ans;
    }
};