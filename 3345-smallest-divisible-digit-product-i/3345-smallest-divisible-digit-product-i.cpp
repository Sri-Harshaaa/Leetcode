class Solution {
public:
    int product(int n) {
        long long pro = 1;
        while(n > 0) {
            int digit = n%10;
            pro*=digit;
            n/=10;
        }
        return pro;
    }
    
    int smallestNumber(int n, int t) {
        while(1) {
            if(product(n)%t==0) return n;
            else n++;
        }
        return 0;
    }
};