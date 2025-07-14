class Solution {
public:
    int getLength(string a,string b) {
        int n = a.size(),m = b.size();
        int i=0,j=0,len=0;
        while(i<n && j<m) {
            if(a[i]==b[j]) {
                len++;
                i++;
                j++;
            }
            else break;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size(),max1=-1,max2=-1;
        vector<int> ans(n);
        vector<int> pre(n),suf(n);
        for(int i=2; i<n; i++) {
            max1 = max(max1,getLength(words[i-1],words[i-2]));
            pre[i] = max1;
        }
        for(int i=n-3; i>=0; i--) {
            max2 = max(max2,getLength(words[i+1],words[i+2]));
            suf[i] = max2;
        }
        for(int i=0; i<n; i++) {
            int temp = max(pre[i],suf[i]);
            ans[i] = (i>0 && i<n-1)? max(temp,getLength(words[i-1],words[i+1])) : temp;
        }
        return ans;
    }
};