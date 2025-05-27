class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        for(int i=0; i<words.size(); i++) {
            mpp[words[i]]++;
        }
        int ans=0,cnt=0;
        for(int i=0; i<words.size(); i++) {
            string rev=words[i];
            reverse(rev.begin(),rev.end());

            if(words[i][0]==words[i][1]) {
                if(mpp[words[i]]==1) {cnt++;
                if(cnt==1) ans+=2;}
                if(mpp[words[i]]>1) {
                    if(mpp[words[i]]%2!=0) {cnt++;
                        if(cnt==1) ans+=2*(mpp[words[i]]);
                        else ans+=2*(mpp[words[i]]-1);
                    }
                    else ans+=2*mpp[words[i]];
                }
                 mpp[words[i]]=0;
            }

            else if(mpp[rev]!=0 && mpp[words[i]]!=0) {
                ans+=4;
                mpp[words[i]]--;
                mpp[rev]--;
            }
        }
        return ans;
    }
};