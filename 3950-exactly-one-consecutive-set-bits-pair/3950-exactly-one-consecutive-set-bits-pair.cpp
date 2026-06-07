class Solution {
public:
    string to_binary(int n) {
        if(n==0) return "0";

        string s;
        while(n) {
            if(n%2) s+="1";
            else s+="0";
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    bool consecutiveSetBits(int n) {
        string s = to_binary(n);
        int count = 0;
        for(int i=1; i<s.size(); i++) {
            if(s[i]=='1' && s[i-1]=='1') count++;
        }
        if(count==1) return true;
        else return false;
    }
};