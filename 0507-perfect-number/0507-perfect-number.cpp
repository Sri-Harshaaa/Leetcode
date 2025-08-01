class Solution {
public:
    bool checkPerfectNumber(int num) {
        int x = 0;
        for(int i=1; i<num; i++) if(num%i==0) x+=i;
        return num==x;
    }
};