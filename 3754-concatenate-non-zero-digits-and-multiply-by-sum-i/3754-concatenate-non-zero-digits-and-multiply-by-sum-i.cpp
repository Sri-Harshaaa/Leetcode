class Solution {
public:
    long long sumAndMultiply(int n) {
        if(!n) return 0;
        string s = to_string(n);
        string temp;
        long long sum = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]!='0') {
                temp+=s[i];
                sum+=(s[i]-'0');
            }
        }
        if(s.empty()) temp+='0';
        long long num = stoi(temp);
        return sum*num;
    }
};