class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size(),cnt = 0;
        string temp = "";
        for(int i=0; i<n; i++) {
            temp+=s[i];
            cnt++;
            if(cnt%k==0) {
                ans.push_back(temp);
                temp = "";
                cnt = 0;
            }
        }
        if(cnt != 0) {
            while(cnt != k) {temp+=fill; cnt++;}
            ans.push_back(temp);
        }
        return ans;
    }
};