class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x==INT_MAX || x==INT_MIN) {
            return false;
        }
        int num=x;
        int digit, reverse=0;
        while(x!=0) {
            if(reverse>INT_MAX/10) return 0;
            digit = x%10;
            reverse = reverse*10 + digit;
            x = x/10;
        }
        cout << reverse;
        if(reverse==num) {
            return true;
        }
        else {
            return false;
        }
    }
};