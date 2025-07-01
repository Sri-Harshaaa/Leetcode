class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> hash(26,1);
        int ans=1;
        for(int i=0; i<word.size()-1; i++) {
            if(word[i]==word[i+1]) hash[word[i]-'a']++;
        }
        for(int x : hash) if(x!=1) ans+=x-1; 
        return ans;
    }
};