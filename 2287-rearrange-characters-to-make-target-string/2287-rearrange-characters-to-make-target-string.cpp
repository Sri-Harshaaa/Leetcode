class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> real, inst;
        for(int i=0; i<target.size(); i++) {
            real[target[i]]++;
        }
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(!real.count(ch)) continue;
            inst[ch]++;
        }
        if(real.size() != inst.size()) return 0;
        int ans = INT_MAX;
        for(auto& it : inst) {
            char ch = it.first;
            int have = it.second;
            int want = real[ch];
            int x = have/want;
            ans = min(ans,x);
        }
        return ans;
    }
};