class Solution {
public:
    bool isValidCode(string s) {
        if(s=="") return false;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(!isalnum(s[i]) && s[i] != '_') return false;
        }
        return true;
    }

    bool isValidBusinessLine(string s) {
        if(s=="electronics" || s=="grocery" || s=="pharmacy" || s=="restaurant") return true;
        else return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        multiset<string> electronics,grocery,pharmacy,restaurant;
        for(int i=0; i<n; i++) {
            string x = businessLine[i];
            string y = code[i];
            if(isValidBusinessLine(x) && isValidCode(y) && isActive[i]) {
                if(x == "electronics") electronics.insert(y);
                else if(x == "grocery") grocery.insert(y);
                else if(x == "pharmacy") pharmacy.insert(y);
                else restaurant.insert(y);
            }
        }
        vector<string> ans;
        for(string s : electronics) ans.push_back(s);
        for(string s : grocery) ans.push_back(s);
        for(string s : pharmacy) ans.push_back(s);
        for(string s : restaurant) ans.push_back(s);
        return ans;
    }
};