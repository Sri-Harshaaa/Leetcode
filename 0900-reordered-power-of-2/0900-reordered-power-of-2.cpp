class Solution {
public:
    string solve(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string str = solve(n);
        for(int i=0; i<=29; i++) {
            if(str==solve(1<<i)) return true;
        }
        return false;
    }
};