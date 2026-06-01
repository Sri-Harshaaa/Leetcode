class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>& parent) {
        int x_leader = find(x,parent);
        int y_leader = find(y,parent);

        if(x_leader == y_leader) return;

        if(x_leader < y_leader) parent[y_leader] = x_leader;
        else  parent[x_leader] = y_leader;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i=0; i<26; i++) {
            parent[i] = i;
        }

        for(int i=0; i<s1.size(); i++) {
            int ch1 = s1[i]-'a';
            int ch2 = s2[i]-'a';
            if(ch1 == ch2) continue;
            Union(ch1,ch2,parent);
        }

        for(int i=0; i<26; i++) {
            find(i,parent);
        }

        for(int i=0; i<baseStr.size(); i++) {
            baseStr[i] = parent[baseStr[i]-'a']+'a';
        }

        return baseStr;
    }
};