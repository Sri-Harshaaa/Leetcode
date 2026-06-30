class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int i = 0, j = 0;
        int a = 0, b = 0, c = 0;
        bool flag = true;
        while(j<n) {
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else  c++;

            if(a && b && c) {
                while(a&&b&&c) {
                    count+=(n-j);
                    if(s[i]=='a') a--;
                    else if(s[i]=='b') b--;
                    else c--;
                    if(j==n-1 && !(a && b && c)) break;
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};