class Solution {
public:
    bool valid(int i,string& s) {
        int n = s.size();
        char ch = s[i];
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch == '-' && i+1<n && i-1>=0) {
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z') return true;
        }
        return false;
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(int i=0; i<chunks.size(); i++) {
            s+=chunks[i];
        }

        unordered_map<string,int> mpp;

        int i=0,n = s.size();
        string temp = "";
        while(i<n) {
            if(valid(i,s)) temp+=s[i];
            else {
                mpp[temp]++;
                temp = "";
            }
            i++;
        }
        if(i==n) mpp[temp]++;

        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            ans.push_back(mpp[queries[i]]);
        }
        return ans;
    }
};